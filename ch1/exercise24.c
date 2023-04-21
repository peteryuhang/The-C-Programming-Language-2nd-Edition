#include <stdio.h>

/* 
 * Write a program to check C program for rudimentary syntax errors like
 * unbalanced parantheses, brackets and braces. Don't forget about quotes,
 * both single and double, escape sequences, and comments.
 */
int getlinestored(char line[]);

// Implement stack by array
void stack_push(char c);
void stack_pop();
char stack_top();

char stack[9999];
int stack_pointer = -1;

int main() {
  int i, line_no, inline_comment, total_len;

  char lines[999999];

  i = inline_comment = 0;
  line_no = 1;
  total_len = getlinestored(lines);
  for (; i < total_len; ++i) {
    // handle comment, disable error checking
    if (i+1 < total_len && lines[i] == '/' && lines[i+1] == '*' && stack_top() != '*') {
      stack_push('*');
      ++i;
      continue;
    }

    if (i+1 < total_len && lines[i] == '/' && lines[i+1] == '/' && stack_top() != '*') {
      inline_comment = 1;
      ++i;
      continue;
    }

    if (i+1 < total_len && lines[i] == '*' && lines[i+1] == '/' && stack_top() == '*') {
      stack_pop();
      ++i;
      continue;
    }

    if (lines[i] == '\n' && inline_comment) {
      inline_comment = 0;
    }

    if (lines[i] == '\n' && stack_top() != '\"' && stack_top() != '\'') {
      ++line_no;
      continue;
    }

    if (stack_top() == '*' || inline_comment) {
      continue;
    }

    // error checking

    // escape
    if (lines[i] == '\\') {
      if (stack_top() != '\"' && stack_top() != '\'') {
        printf("Unexpected \\ on line %d\n", line_no);
        return 1;
      }
      ++i;
      continue;
    }

    if (lines[i] == '\"' && stack_top() != '\'') {
      if (stack_top() == '\"') {
        stack_pop();
        if (stack_top() == '\"') {
          printf("Unexpected \" on line %d\n", line_no);
        }
      } else {
        stack_push(lines[i]);
      }
      continue;
    }

    if (lines[i] == '\'' && stack_top() != '\"') {
      if (stack_top() == '\'') {
        stack_pop();
        if (stack_top() == '\'') {
          printf("Unexpected \' on line %d\n", line_no);
          return 1;
        }
      } else {
        stack_push(lines[i]);
      }
      continue;
    }

    if ((lines[i] == '(' || lines[i] == '[' || lines[i] == '{') 
          && stack_top() != '\'' && stack_top() != '\"' ) {
      stack_push(lines[i]);
      continue;
    }

    if (lines[i] == ')' && stack_top() != '\'' && stack_top() != '\"') {
      if (stack_top() != '(') {
        printf("Unexpected ) on line %d\n", line_no);
        return 1;
      } else {
        stack_pop();
      }
      continue;
    }

    if (lines[i] == ']' && stack_top() != '\'' && stack_top() != '\"') {
      if (stack_top() != '[') {
        printf("Unexpected ] on line %d\n", line_no);
        return 1;
      } else {
        stack_pop();
      }
      continue;
    }

    if (lines[i] == '}' && stack_top() != '\'' && stack_top() != '\"') {
      if (stack_top() != '{') {
        printf("Unexpected } on line %d\n", line_no);
        return 1;
      } else {
        stack_pop();
      }
    }
  }

  printf("Checking finished, doesn't find any syntax error, C program totoal line %d\n", line_no);

  return 0;
}

int getlinestored(char s[]) {
  int c, i;

  for (i = 0; (c=getchar()) != EOF; ++i)
    s[i] = c;

  s[i] = '\0';

  return i;
}

void stack_push(char c) {
  extern char stack[];
  extern int stack_pointer;

  stack[++stack_pointer] = c;
}

void stack_pop() {
  extern int stack_pointer;
  --stack_pointer;
}

char stack_top() {
  extern char stack[];
  extern int stack_pointer;

  if (stack_pointer < 0) {
    return '\0';
  }

  return stack[stack_pointer];
}

