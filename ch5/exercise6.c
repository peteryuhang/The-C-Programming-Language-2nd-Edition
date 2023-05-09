#include <stdio.h>
#include <ctype.h>

int getline_m(char* s, int lim);
int atoi_m(char* s);
void itoa_m(int n, char* s);
double atof(char* s);
void reverse(char* s);
int strindex(char* s, char* t);
int getop(char* s);
int getch(void);
void ungetch(int c);


#define NUMBER '0'    /* signal that a number was found */

/* 
 * Rewrite appropriate programs from earlier chapters and exercise with
 * pointers instead of array indexing. Good possibilities include getline,
 * atoi, itoa, and their variants, reverse, and strindex and getop
 */
int main() {
  char s[100];

  // printf("%d\n", getline_m(s, 100));
  
  // printf("%d\n", atoi_m(s));
  
  // itoa_m(-21319, s);
  // printf("%s\n", s);

  // printf("%lf\n", atof("-2391.2039"));

  // reverse(s);
  // printf("%s\n", s);

  // printf("%d\n", strindex("hello world", "hello"));

  printf("%c\n", getop(s));

  return 0;
}

/*
 * getline: Read line into s, return length
 */
int getline_m(char* s, int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
    *s++ = c;
  
  if (c == '\n') {
    *s++ = c;
    ++i;
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

/* itoa: convert integer to string */
void itoa_m(int n, char* s) {
  int sign;
  char* sp = s;

  sign = 1;
  if (n < 0)    /* record sign */
    sign = -1;

  do {
    *sp++ = (n % 10) * sign + '0';
  } while ((n /= 10) != 0);

  if (sign < 0)
    *sp++ = '-';
  *sp = '\0';

  reverse(s);
}

/* atof: convert s to float */
double atof(char* s) {
  double val, power;
  int sign;

  for (; isspace(*s); ++s)  /* skip the white space */
    ;
  sign = (*s == '-') ? -1 : 1;
  if (*s == '+' || *s == '-')
    ++s;
  for (val = 0.0; isdigit(*s); ++s)
    val = 10.0 * val + (*s - '0');
  if (*s == '.')
    ++s;
  for (power = 1.0; isdigit(*s); ++s) {
    val = 10.0 * val + (double)(*s - '0');
    power *= 10.0;
  }
  return sign * val / power;
}

/* 
 * reverse: reverse the input string
 */
void reverse(char* s) {
  char* e = s;
  int tmp;
  while (*e)
    e++;
  e--;

  while (e > s) {
    tmp = *e;
    *e-- = *s;
    *s++ = tmp;
  }
}

/* strindex: return index of t in s, -1 of none */
int strindex(char* s, char* t) {
  int i;
  char* ss;
  char* st;

  for (i = 0; *s != '\0'; ++s) {
    for (ss = s, st = t; (*st != '\0') && (*ss == *st); ++ss, ++st)
      ;
    if (*st == '\0')
      return i;
  }

  return -1;
}

/* getop: get next operator or numeric operand */
int getop(char* s) {
  int c, tmp;

  while ((*s = c = getch()) == ' ' || c == '\t')
    ;
  *(s+1) = '\0';

  if (!isdigit(c) && c != '.') {
    // check whether it is a negative number
    if (c == '-' && isdigit(tmp = getch())) {
      *++s = c = tmp;
    } else {
      return c;       /* not a number */
    }
  }

  if (isdigit(c))   /* collect integer part */
    while (isdigit(*++s = c = getch()));

  if (c == '.')     /* collect fraction part */
    while (isdigit(*++s = c = getch()));

  *s = '\0';
  if (c != EOF)
    ungetch(c);

  return NUMBER;
}

// =======================================================

/* 
 * getch delivers the next input character to be considered;
 * ungetch remembers the characters put back on the input, so
 * that subsequent calls to getch will return them before reading
 * new input
 */

#define BUFSIZE 100

char buf[BUFSIZE];              /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void) {       /* get a (possibly pushed back) character */
  return (bufp > 0) ? *(buf + (--bufp)) : getchar();
}

void ungetch(int c) {     /* push character back on input */
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters");
  else {
    *(buf + bufp++) = c;
  }
}
