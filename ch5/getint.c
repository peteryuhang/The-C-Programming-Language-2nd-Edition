#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *);

int main() {
  int n;
  int *ip;
  ip = &n;

  printf("getint(ip) return: %d\n", getint(ip));
  printf("*ip: %d, n: %d\n", *ip, n);
  return 0;
}

/* 
 * getint: get next integer from input into *pn
 * 
 * This version of getint returns EOF for end of file,
 * zero if the next input is not a number, positive value
 * if the input contains a valid number
 */
int getint(int *pn) {
  int c, sign;

  while (isspace(c = getch()))    /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

// =======================================================

/* 
 * getch delivers the next input character to be considered;
 * ungetch remembers the characters put back on the input, so
 * that subsequent calls to getch will return them before reading
 * new input
 */
#define BUFSIZE 100

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void) {       /* get a (possibly pushed back) character */
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {     /* push character back on input */
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters");
  else
    buf[bufp++] = c;
}
