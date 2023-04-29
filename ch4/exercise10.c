#include <stdio.h>
#include <stdlib.h>   /* for atof */
#include <ctype.h>

#define MAXOP 100        /* max size of operand or operator */
#define MAXLINE 1000     /* max size of line */
#define NUMBER '0'       /* signal that a number was found */

int getop(char[]);
void push(double);
double pop(void);
int getlinestored(char[], int);

/*
 * An alternate organization uses getline to read an entire input line;
 * this make getch and ungetch unnecessary. Revise the calculator to use
 * this approach
 */
int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      /* 
       * + and * are commutative operators, but for - and /
       * the left and right operands must be distinguished
       */
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

// =======================================================

#define MAXVAL 100    /* maximum depth of val stack */

int sp = 0;           /* next free stack position */
double val[MAXVAL];   /* value stack */

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

// ================= Read op from Line ===============
int linep = 0;
char line[MAXLINE];

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  if (line[linep] == '\0') {
    if (getlinestored(line, MAXLINE) == 0)
      return EOF;
    else
      linep = 0;
  }

  int i, c;
  while ((s[0] = c = line[linep++]) == ' ' || c == '\t');

  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;       /* not a number */
  i = 0;
  if (isdigit(c))   /* collect integer part */
    while (isdigit(s[++i] = c = line[linep++]));
  if (c == '.')     /* collect fraction part */
    while (isdigit(s[++i] = c = line[linep++]));
  s[i] = '\0';

  --linep;

  return NUMBER;
}

/*
 * getlinestored: Read line into s, return length 
 */
int getlinestored(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';

  return i;
}
