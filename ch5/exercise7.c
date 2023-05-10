#include <stdio.h>
#include <string.h>

/* 
 * Rewrite readlines to store lines in an array supplied by main, rather than
 * calling alloc to maintain storage. How much faster is the program
 */
#define MAXLINES 5000     // max lines to be sorted
#define MAXLEN 1000    // max length of any input line

char *lineptr[MAXLINES];  // pointers to text lines

int readlines(char *lineptr[], char *p, int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int getlinestored(char *, int);

int main() {
  int nlines;
  char p[600000];

  if ((nlines = readlines(lineptr, p, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

/* readlines: read input lines */
int readlines(char *lineptr[], char *p, int maxlines) {
  int len, nlines;
  char line[MAXLEN];

  nlines = 0;
  while ((len = getlinestored(line, MAXLEN)) > 0) {
    if (nlines >= maxlines) {
      return -1;
    } else {
      line[len-1] = '\0';    // delete newline
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len;
    }
  }
  
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);     // **
}

/* getlinestored: Read line into s, return length */
int getlinestored(char *s, int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++s, ++i)
    *s = c;
  
  if (c == '\n') {
    *s++ = c;
    i++;
  }

  *s = '\0';

  return i;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right) {
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; ++i)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
  char *tmp;

  tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}