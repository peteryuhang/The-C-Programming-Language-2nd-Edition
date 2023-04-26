#include <stdio.h>

/* 
 * Write the function itob(n,s,b) that converts the integer n into a base b character
 * representation in the string s. In particular, itob(n,s,16) formats n as a hexadecimal
 * integer in s
 */
void itob(int n, char s[], int b);
char c2digit(int m);
void reverse(char s[]);

int main() {
  char s[999];

  itob(104, s, 2);
  printf("%s\n", s);
}

void itob(int n, char s[], int b) {
  int i, sign;

  sign = 1;
  if (n < 0)    /* record sign */
    sign = -1;

  i = 0;
  do {
    s[i++] = c2digit(n % b * sign);
  } while ((n /= b) != 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';

  reverse(s);
}

/* 
 * convert remainder number into single digit or letter
 * if remainder number is less than 10, represent it by digit ('0' ~ '9')
 * if remainder number is larger or equal to 10, represent it by lower case alphabet ('a' ~ 'z')
 */
char c2digit(int m) {
  return m < 10 ? m + '0' : (m - 10) + 'a';
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
