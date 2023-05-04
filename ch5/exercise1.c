#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *);


/* 
 * As written, getint treats a + or - not followed by a digit as a valid representation
 * of zero. Fix it to push such a character back on the input
 */
int main() {
  int n;
  int *ip;
  ip = &n;

  printf("getint(ip) return: %d\n", getint(ip));
  printf("*ip: %d, n: %d\n", *ip, n);
  return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
  int c, sign, is_sign;

  while (isspace(c = getch()))    /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  is_sign = (c == '+' || c == '-');
  if (is_sign)
    c = getch();
  if (!isdigit(c)) {
    ungetch(c);
    if (is_sign)
      ungetch((sign == -1) ? '-' : '+');
    return 0;
  }
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
