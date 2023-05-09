#include <stdio.h>

void strcat_m(char *s, char *t);

/* 
 * Write a pointer version of the function strcat that we showed in Chapter 2:
 * strcat(s,t) copies the string t to the end of s
 */
int main() {
  char s[100] = "hello world ";
  char t[] = "hello world again";

  strcat_m(s, t);
  printf("%s\n", s);
  return 0;
}

/* strcat: copies the string t to the end of s */
void strcat_m(char *s, char *t) {
  while (*s)
    s++;
  while (*s++ = *t++);
}
