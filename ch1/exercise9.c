#include <stdio.h>

/* 
 * Write a program to copy its input to its output replacing each
 * string of one or more blanks by a single blank
 */
int main() {
  int c, prev;

  prev = EOF;
  while ((c = getchar()) != EOF) {
    if (prev != ' ' || c != prev)
      putchar(c);
    prev = c;
  }
}
