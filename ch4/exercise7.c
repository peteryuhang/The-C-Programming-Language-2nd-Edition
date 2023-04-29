#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void);
void ungetch(int c);
void ungets(char s[]);
int getlinestored(char s[], int lim);

/* 
 * Write a routine ungets(s) that will push back an entire string onto the input.
 * Should ungets know about buf and bufp, or should it just use ungetch?
 * 
 * Answer: ungets can reuse ungetch, so ungets no need to know the detail implementation
 * of ungetch, eg. buf, bufp, etc. Function help hide the lower level detail thing which
 * make the program easier for understanding and maintaining
 */
int main() {
  char line[1000];
  int c;

  getlinestored(line, BUFSIZE);

  ungets(line);

  while ((c = getch()) != EOF)
    putchar(c);
  return 0;
}

int getch(void) {         /* get a (possibly pushed back) character */
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {     /* push character back on input */
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters");
  else
    buf[bufp++] = c;
}

void ungets(char s[]) {
  int i;

  i = strlen(s);
  while (i > 0)
    ungetch(s[--i]);
}

/*
 * getlinestored: Read line into s, return length 
 */
int getlinestored(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (i > 0 && c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}