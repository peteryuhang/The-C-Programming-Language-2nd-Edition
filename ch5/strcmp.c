#include <stdio.h>

int strcmp_arr(char *s, char *t);
int strcmp_ptr(char *s, char *t);

int main() {
  char s[100];

  printf("%d\n", strcmp_ptr("hello", "hello, world\n"));
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp_arr(char *s, char *t) {
  int i;

  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp_ptr(char *s, char *t) {
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}
