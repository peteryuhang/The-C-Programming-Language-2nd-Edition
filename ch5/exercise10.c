#include <stdio.h>
#include <stdlib.h>   /* for atof */
#include <ctype.h>

#define MAXOP 100     /* max size of operand or operator */
#define NUMBER '0'    /* signal that a number was found */

int getop(char *, char *);
void push(double);
double pop(void);

/*
 * Write the program expr, which evaluates a reverse Polish expression from the
 * command line, where each operator or operand is a separate argument. For example,
 *      expr 2   3   4    +    *
 * evaluates 2 x (3+4)
 */


/*
 * Remember to escape the special charater in command-line, eg. * which have special meaning
 *
 * $> a.out 2 3 4 + \* 
 */ 
int main(int argc, char *argv[]) {
  int type;
  double op2;
  char s[MAXOP];

  while ((*++argv) && (type = getop(s, argv[0]))) {
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
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }

  printf("\t%.4g\n", pop());

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

// =======================================================

/* getop: get next operator or numeric operand */
int getop(char *s, char *p) {
  int c;

  while ((*s = c = *p++) == ' ' || c =='\t');

  *(s+1) = '\0';
  if (!isdigit(c) && c != '.')
    return c;       /* not a number */

  if (isdigit(c))   /* collect integer part */
    while (isdigit(*++s = c = *p++));

  if (c == '.')     /* collect fraction part */
    while (isdigit(*++s = c = *p++));

  *s = '\0';

  return NUMBER;
}
