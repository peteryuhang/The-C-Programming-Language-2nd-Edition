#include <stdio.h>
#include <string.h>
#include <stdlib.h>   // for atof
#include <ctype.h>

#define MAXLINES 5000     // max lines to be sorted
char *lineptr[MAXLINES];  // pointers to text lines

void getflag(int, char *[], int *, int *, int *, int *);
int readlines(char *[], int nlines, int exclude);
void writelines(char *[], int nlines);

void qsort_m(void *[], int, int,
           int (*)(void *, void *), int);
int numcmp(char *, char *);
int strcmp_case_ignore(char *, char *);
void* select_cmp_func(int, int);


/* 
 * Add the -d ("directory order") option, which makes comparisons only on letters,
 * number, and blanks. Make sure it works in conjunction with -f
 */
int main(int argc, char *argv[]) {
  int nlines;
  int numeric = 0;
  int reverse = 0;
  int case_ignore = 0;
  int directory_order = 0;

  getflag(argc, argv, &numeric, &reverse, &case_ignore, &directory_order);

  if ((nlines = readlines(lineptr, MAXLINES, directory_order)) >= 0) {
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
void getflag(int argc, char *argv[], int *numeric, int *reverse, int *case_ignore, int *directory_order) {
  int c;

  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
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
}

#define MAXLEN 1000    // max length of any input line

int getlinestored(char *, int, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, int exclude) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getlinestored(line, MAXLEN, exclude)) > 0) {
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
