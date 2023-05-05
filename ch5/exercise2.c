#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getfloat(float *);


/* 
 * Write getfloat, the float-point analog of getint. What type does getfloat return
 * as its function value?
 * 
 * Answer: int, because the returned thing/strategy still same as before
 */
int main() {
  float f;
  float *fp;
  fp = &f;

  printf("getfloat(fp) return: %d\n", getfloat(fp));
  printf("*fp: %f, f: %f\n", *fp, f);
  return 0;
}

/* getfloat: get next float from input into *pn */
int getfloat(float *pf) {
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

  for (*pf = 0; isdigit(c); c = getch())
    *pf = 10 * *pf + (c - '0');
  if (c == '.')
    c = getch();
  
  float power;
  for (power = 10.0; isdigit(c); c = getch()) {
    *pf += (c - '0') / power;
    power *= 10.0;
  }
  *pf *= sign;
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
