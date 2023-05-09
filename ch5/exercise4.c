#include <stdio.h>

int strend_m(char *s, char *t);

/* 
 * Write the function strend(s,t), which returns 1 if the string t
 * occurs at the end of the string s, and zero otherwise
 */
int main() {
  char s[100] = "hello hello hello";
  char t[] = "hello";

  printf("%d\n", strend_m(s, t));
  return 0;
}

/* strend: returns 1 if the string t occurs at the end of the string s, and zero otherwise */
int strend_m(char *s, char *t) {
  int i;

  for (i = 0; *s != '\0'; s++) {
    if (*s == *t) {
      i++;
      t++;
    } else {
      t = t - i;
      i = 0;
    }
  }

  return *t == '\0' ? 1 : 0;
}
