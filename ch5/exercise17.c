#include <stdio.h>
#include <string.h>
#include <stdlib.h>   // for atof
#include <ctype.h>

#define MAXLINES 5000     // max lines to be sorted
char *lineptr[MAXLINES];  // pointers to text lines

void getflag(int, char *[], int *, int *, int *, int *, int *);
int readlines(char *[], int, int, int);
void writelines(char *[], int);

void qsort_m(void *[], int, int,
           int (*)(void *, void *), int);
int numcmp(char *, char *);
int strcmp_case_ignore(char *, char *);
void* select_cmp_func(int, int);
int atoi_m(char *);


/* 
 * Add a field-handling capabilitym so sorting may be done on fields within lines,
 * each field sorted according to an independent set of options. (The index for this
 * book was sorted with -df for the index category and -n for the page number)
 */
int main(int argc, char *argv[]) {
  int nlines;
  int numeric = 0;
  int reverse = 0;
  int case_ignore = 0;
  int directory_order = 0;
  int field_pos = 0;

  getflag(argc, argv, &numeric, &reverse, &case_ignore, &directory_order, &field_pos);
  printf("numeric: %d, reverse: %d, case_ignore: %d, directory_order: %d, field_pos: %d\n", numeric, reverse, case_ignore, directory_order, field_pos);

  if ((nlines = readlines(lineptr, MAXLINES, directory_order, field_pos)) >= 0) {
    qsort_m((void **)lineptr, 0, nlines - 1, select_cmp_func(numeric, case_ignore), reverse);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

void* select_cmp_func(int numeric, int case_ignore) {
  if (numeric)
    return numcmp;
  return case_ignore ? strcmp_case_ignore : strcmp;
}

/* getflag: parse the options from the command line input */
void getflag(int argc, char *argv[], int *numeric, int *reverse, int *case_ignore, int *directory_order, int *field_pos) {
  int c;

  while (--argc > 0 && (*++argv)[0] == '-') {
    while (c = *++argv[0])
      if (!isdigit(c))
        switch (c)
        {
        case 'n':
          *numeric = 1;
          break;
        case 'r':
          *reverse = 1;
          break;
        case 'f':
          *case_ignore = 1;
          break;
        case 'd':
          *directory_order = 1;
          break;
        default:
          printf("find: illegal option %c\n", c);
          break;
        }
      else {
        *field_pos = atoi_m(argv[0]);
        break;
      }
  }
}

#define MAXLEN 1000    // max length of any input line

int getlinestored(char *, int, int);
int getfield(char *, int, int, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, int exclude, int field_pos) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;

  while ((len = field_pos > 0 ? getfield(line, MAXLEN, exclude, field_pos)
                              : getlinestored(line, MAXLEN, exclude)) > 0) {
    if (nlines >= maxlines || (p = alloc(len)) == NULL) {
      return -1;
    } else {
      line[len-1] = '\0';    // delete newline
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);     // **
}

/*
 * getlinestored: Read line into s, return length 
 */
int getlinestored(char *s, int lim, int exclude) {
  int c, i;

  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n';)
    if (!exclude || isdigit(c) || isalpha(c) || isblank(c)) {
      *s++ = c;
      i++;
    }
  
  if (c == '\n') {
    *s++ = c;
    i++;
  }

  *s = '\0';

  return i;
}

/*
 * getfield: Read nth (start from 1) field line into s, return length
 */
int getfield(char *s, int lim, int exclude, int n) {
  int c, i, prev, pass;

  prev = 0;
  while (n > 1 && (c=getchar()) != EOF && c != '\n')
    if (c == ' ' || c == '\t') {
      if (!prev)
        n--;
      prev = 1;
    } else {
      prev = 0;
    }

  while ((c == ' ' || c == '\t') && ((c=getchar()) == ' ' || c == '\t'));

  pass = 0;
  for (i = 0; i < lim - 1 && c != EOF && c != '\n'; c=getchar()) {
    if (pass || c == ' ' || c == '\t') {
      pass = 1;
      continue;
    }

    if (!exclude || isdigit(c) || isalpha(c) || isblank(c)) {
      *s++ = c;
      i++;
    }
  }

  if (c == '\n' || c == ' ' || c == '\t') {
    *s++ = c;
    i++;
  }

  *s = '\0';

  return i;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE] = "hello";    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */

/* 
 * return pointer to n characters
 */
char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else {     // not enough room
    return 0;
  }
}

// free storage pointed to by p
void afree(char *p) {
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort_m(void *v[], int left, int right, int (*comp)(void *, void *), int reverse) {
  int i, last;
  void swap(void *v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; ++i)
    if ((!reverse && (*comp)(v[i], v[left]) < 0)
       || (reverse && (*comp)(v[i], v[left]) > 0))
      swap(v, ++last, i);
  swap(v, left, last);
  qsort_m(v, left, last-1, comp, reverse);
  qsort_m(v, last+1, right, comp, reverse);
}

int numcmp(char *s1, char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

int strcmp_case_ignore(char *s, char *t) {
  int gap = 'a' - 'A';

  for (; (*s == *t) || (*s + gap == *t) || (*s - gap == *t); s++, t++)
    if (*s == '\0')
      return 0;

  if (*s >= 'a' && *s <= 'z' && *t >= 'A' && *t <= 'Z') {
    return *s - (*t + gap);
  }

  if (*s >= 'A' && *s <= 'Z' && *t >= 'a' && *t <= 'z') {
    return *s - (*t - gap);
  }

  return *s - *t;
}

void swap(void *v[], int i, int j) {
  void *tmp;

  tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}

/* atoi: convert s to integer */
int atoi_m(char* s) {
  int n;

  n = 0;
  for (; *s >= '0' && *s <= '9'; s++)
    n = 10 * n + (*s - '0');
  return n;
}
