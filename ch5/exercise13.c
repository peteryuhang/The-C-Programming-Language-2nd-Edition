#include <stdio.h>
#include <string.h>

#define MAXLEN 1000               // max character per line
#define DEFAULT_OUTPUT_SIZE 10    // default n

int readlines(char *[], char *, int);
void writelines(char *[], int, int);
int getlinestored(char *, int);
int atoi_m(char *);

/* 
 * Write the program tail, which prints the last n lines of its input.
 * By default, n is 10, let us say, but it can be changed by an optional
 * argument, so that
 *    tail -n 
 * prints the last n line. The program should behave rationally no matter
 * how unreasonable the input or the value of n. Write the program so it
 * makes the best use of available storage; lines should be stored as in
 * the sorting program of Section 5.6, not in a two-dimensional array of
 * fixed size
 */
int main(int argc, char *argv[]) {
  int start, i;
  int n = DEFAULT_OUTPUT_SIZE;

  // read n from the commandline argument
  if (argc > 1 && (*++argv)[0] == '-')
    n = atoi_m(++argv[0]);

  // if couldn't get valid n, set it back to default value
  if (n <= 0)
    n = DEFAULT_OUTPUT_SIZE;

  char *lineptr[n];           // pointers to text lines
  for (i = 0; i < n; ++i)     // initialize pointers to 0, otherwise they will point to random contant
    lineptr[i] = NULL;

  char allocbuf[n * MAXLEN];  // storage for lines

  start = readlines(lineptr, allocbuf, n);

  writelines(lineptr, start, n);

  return 0;
}

/* readlines: read input lines */
int readlines(char *lineptr[], char *allocbuf, int maxlines) {
  int len, nlines, total;
  char *p;

  p = allocbuf;
  nlines = total = 0;
  while ((len = getlinestored(p, MAXLEN)) > 0) {
    // rotate the storage
    if (total + len >= maxlines * MAXLEN) {
      p = allocbuf;
      total = 0;
    }

    // rotate the pointers array
    if (nlines == maxlines)
      nlines = 0;

    p[len-1] = '\0';    // delete newline
    lineptr[nlines++] = p;
    p += len;
    total += len;
  }

  return nlines == maxlines ? 0 : nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int start, int n) {
  int len = n;

  printf("The last %d line:\n", n);
  while (n-- > 0) {
    if (lineptr[start] != NULL) {
      printf("%s\n", lineptr[start]);     // **
    }

    if (++start >= len)
      start = 0;
  }
}

/* getlinestored: Read line into s, return length */
int getlinestored(char *s, int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++s, ++i) {
    *s = c;
  }
  
  if (c == '\n') {
    *s++ = c;
    i++;
  }

  *s = '\0';

  return i;
}

/* atoi: convert s to integer */
int atoi_m(char* s) {
  int n;

  n = 0;
  for (; *s >= '0' && *s <= '9'; s++)
    n = 10 * n + (*s - '0');
  return n;
}
