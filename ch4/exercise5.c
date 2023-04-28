#include <stdio.h>
#include <stdlib.h>   /* for atof */
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100     /* max size of operand or operator */
#define NUMBER '0'    /* signal that a number was found */
#define MATHFUNC 'n'  /* signal that use math functions */

int getop(char[]);
void push(double);
double pop(void);

double top(void);
void dup(void);
void swap(void);
void clear(void);

void math_func(char[]);


/*
 * Add access to library functions like sin, exp and pow
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
    case MATHFUNC:
      math_func(s);
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      /* 
       * + and * are commutative operators, but for -, / and %
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
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push(fmod(pop(), op2));
      else
        printf("error: modulo by zero\n");
      break;
    // print the top element
    case 't':
      printf("the top element is %lf", top());
      break;
    // duplicate the top element
    case 'd':
      dup();
      break;
    // swap the top two elements
    case 's':
      swap();
      break;
    // clear the stack
    case 'c':
      clear();
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
    printf("error of pop: stack empty\n");
    return 0.0;
  }
}

/* top: return top value from stack */
double top(void) {
  if (sp > 0)
    return val[sp];
  else {
    printf("error of top: stack empty\n");
    return 0.0;
  }
}

/* dup: duplicate the top element */
void dup(void) {
  if (sp > 0) {
    val[sp] = val[sp - 1];
    ++sp;
  } else {
    printf("error of duplicate: stack empty\n");
  }
}

/* swap: swap the top two elements */
void swap(void) {
  int tmp;
  if (sp >= 2)
    tmp = val[sp - 1], val[sp - 1] = val[sp - 2], val[sp - 2] = tmp;
  else
    printf("error of swap: stack element not enough\n");
}

/* clear: clear the stack */
void clear(void) {
  sp = 0;
}

/* math_func: based on string s to apply corresponding math function */
void math_func(char s[]) {
    double op2;

    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else
        printf("error: %s is not supported\n", s);
}

// =======================================================

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int i, c, tmp;

  while ((s[0] = c = getch()) == ' ' || c =='\t')
    ;
  s[1] = '\0';

  i = 0;
  if (islower(c)) {
    while (islower(s[++i] = c = getch()))
      ;
    s[i] = '\0';
    if (c != EOF)
      ungetch(c);
    if (strlen(s) > 1)
      return MATHFUNC;
    else
      return s[0];
  }
  if (!isdigit(c) && c != '.') {
    // check whether it is a negative number
    if (c == '-' && isdigit(tmp = getch())) {
      s[++i] = c = tmp;
    } else {
      return c;       /* not a number */
    }
  }
  if (isdigit(c))   /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')     /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
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
