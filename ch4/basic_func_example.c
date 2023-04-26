#include <stdio.h>

#define MAXLINE 1000

int getlinestored(char t[], int lim);
int strindex(char s[], char t[]);

char pattern[] = "ould";     /* pattern to search for */

/* find all lines matching pattern */
int main() {
  char line[MAXLINE];
  int found = 0;

  while (getlinestored(line, MAXLINE) > 0) {
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      ++found;
    }
  }

  return found;
}

/* getlinestored: get line into s, return length */
int getlinestored(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim && (c=getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';
  return i;
}

/* strindex: return index of t in s, -1 of none */
int strindex(char s[], char t[]) {
  int i, j, k;

  for (i = 0; s[i] != '\0'; ++i) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }

  return -1;
}
