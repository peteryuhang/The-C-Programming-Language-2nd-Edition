#include <stdio.h>

/* 
 * In a two's complement number representation, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to -(2^(wordsize-1)).
 * Explain why not. Modify it to print that value correctly, regardless of the machine
 * on which it runs
 * 
 * Explain: Because for integer, the value range is [-2^(wordsize-1), 2^(wordsize-1) - 1]
 * the program will be wrong during n = -n, the -n is too large to handle
 */
void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
  char s[999];

  itoa(-2147483648, s);
  printf("%s\n", s);
}

void itoa(int n, char s[]) {
  int i, sign;

  sign = 1;
  if (n < 0)    /* record sign */
    sign = -1;

  i = 0;
  do {
    s[i++] = (n % 10) * sign + '0';
  } while ((n /= 10) != 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';

  reverse(s);
}

/* 
 * reverse: reverse the input string
 */
void reverse(char s[]) {
  int i, j, tmp;
  for (i = 0; s[i] != '\0'; ++i)
    ;
  for (j = 0, i = i - 1; i > j; --i, ++j) {
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
}
