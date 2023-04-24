#include <stdio.h>

/* 
 * Rewrite the function lower, which converts upper case letters to lower case,
 * with a conditional expression instead of if-else 
 */
int lower(int c);

int main() {
  printf("The output for lower('A') is %c\n", lower('A'));
}

int lower(int c) {
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}