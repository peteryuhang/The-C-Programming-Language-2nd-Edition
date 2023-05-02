#include <stdio.h>

/* 
 * Adapt the ideas of printd to write a recursive version of itoa;
 * that is, convert an integer into a string by calling a recursive routine
 */
int itoa(int, char[], unsigned int);

int main() {
  char s[999];

  itoa(-2147483111, s, 0);
  printf("%s\n", s);
}

/* the length of string will be returned */
int itoa(int n, char s[], unsigned int i) {
  if (n < 0) {     /* record sign */
    n = -n;
    s[i++] = '-';
  }

  if (n / 10)
    i = itoa(n / 10, s, i);
  s[i++] = (n % 10) + '0';
  s[i] = '\0';

  return i;
}
