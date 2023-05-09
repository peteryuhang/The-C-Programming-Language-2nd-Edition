#include <stdio.h>

char* strncpy_m(char *s, char *t, int n);
char* strncat_m(char *s, char *t, int n);
int strncmp_m(char *s, char *t, int n);

/* 
 * Write versions of the library functions strncpy, strncat, and strncmp,
 * which operate on at most the first n characters of their argument strings.
 * For example, strncpy(s,t,n) copies at most n characters of t to s.
 */
int main() {
  char s[100] = "hello hello hello ";
  char t[] = "hello";

  // printf("%s\n", strncpy_m(s, t, 1));
  // printf("%s\n", strncat_m(s, t, 2));
  printf("%d\n", strncmp_m(s, t, 6));
  return 0;
}

/*
 * strncpy: copy at most n characters of string t to string s
 * Pad with '\0's if t has fewer than n characters
 */
char* strncpy_m(char *s, char *t, int n) {
  char* sp = s;

  while ((sp - s < n) && (*sp++ = *t++));

  while (sp - s < n)
    *sp++ = '\0';

  if (*sp != '\0')
    *sp = '\0';

  return s;
}

/*
 * strncat: concatenate at most n characters of string t to string s,
 * terminate s with '\0'; return s
 */
char* strncat_m(char *s, char *t, int n) {
  int i = 0;
  char* sp = s;

  while (*sp)
    sp++;

  while ((i++ < n) && (*sp++ = *t++));

  if (*sp)
    *sp = '\0';

  return s;
}

/*
 * strncmp: compare at most n characters of string s to string t,
 * return <0 if s<t, 0 if s==t, or >0 if s>t
 */
int strncmp_m(char *s, char *t, int n) {
  int i;

  for (i = 0; *s == *t && i < n; i++, s++, t++)
    if (*s == '\0')
      return 0;

  return *s - *t;
}
