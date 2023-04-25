#include <stdio.h>

/* 
 * Write a function expand(s1,s2) that expands shorthand notations like a-z in
 * the string s1 into the equivalent complete list abc...xyz in s2. Allow for
 * letters of either case and digits, and be prepared to handle cases like a-b-c
 * and a-z0-9 and -a-z. Arrage that a leading or trailing - is taken literally
 */
void expand(char s1[], char s2[]);
void getlines(char t[], int lim);
int isDigitOrLetter(char c);

int main() {
  char s1[99999];
  char s2[99999 * 2];
  getlines(s1, 99997);
  expand(s1, s2);

  printf("%s\n", s2);
}

void expand(char s1[], char s2[]) {
  int i, j, k;

  for (i = 0, j = 0; s1[i] != '\0'; ++i) {
    if (i > 0 && s1[i] == '-' && isDigitOrLetter(s1[i-1]) && isDigitOrLetter(s1[i+1])) {
      /* 
       * assuming the range operands been given correctly
       * things like 0-a, z-a, a-B, A-b doesn't expected as input 
       * and will output unexpected result
       */
      for (k = s1[i-1] + 1; k < s1[i+1]; ++k) {
        s2[j++] = k;
      }

      if (s1[i-1] == s1[i+1]) {
        ++i;
      }
    } else {
      s2[j++] = s1[i];
    }
  }
  s2[j] = '\0';
}

void getlines(char t[], int lim) {
  int c, i;

  for (i = 0; i < lim && (c=getchar()) != EOF; ++i)
    t[i] = c;

  t[i] = '\0';
}

int isDigitOrLetter(char c) {
  if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
    return 1;
  }
  return 0;
}