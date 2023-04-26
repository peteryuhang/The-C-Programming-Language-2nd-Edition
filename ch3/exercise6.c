#include <stdio.h>

/* 
 * Write a version of itoa that accepts three arguments instead of two.
 * The third argument is a minimum field width; the converted number must
 * be padded with blanks on the left if necessary to make it wide enough
 */
void itoa(int n, char s[], int w);
void reverse(char s[]);

int main() {
  char s[999];

  itoa(-2147483648, s, 15);
  printf("%s\n", s);
}

void itoa(int n, char s[], int w) {
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
  
  while (i < w)
    s[i++] = ' ';

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
    tmp = s[i], s[i] = s[j], s[j] = tmp;
  }
}
