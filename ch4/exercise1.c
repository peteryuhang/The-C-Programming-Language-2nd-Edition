#include <stdio.h>

#define MAXLINE 1000

int getlinestored(char t[], int lim);
int strrindex_v1(char s[], char t[]);
int strrindex_v2(char s[], char t[]);

char pattern[] = "ould";     /* pattern to search for */

/* 
 * Write the function strrindex(s,t), which returns the position of the
 * rightmost occurrence of t in s, or -1 if there is none
 */
int main() {
  char line[MAXLINE];
  int found = 0;
  int pos = 0; /* start from 0 */

  while (getlinestored(line, MAXLINE) > 0) {
    if ((pos=strrindex_v2(line, pattern)) >= 0) {
      printf("%d\n", pos);
      ++found;
    }
  }

  return found;
}

/* strrindex_v1: return rightmost index of t in s, -1 of none */
int strrindex_v1(char s[], char t[]) {
  int i, j, l, k;

  for (i = 0; s[i] != '\0'; ++i)
    ;
  for (l = 0; t[l] != '\0'; ++l)
    ;

  for (i=i-1; i >= 0; --i) {
    for (j=i, k=l-1; k >= 0 && s[j] == t[k]; --j, --k)
      ;
    if (k < 0)
      return i - l + 1;
  }

  return -1;
}

/* strrindex_v2: return rightmost index of t in s, -1 of none */
int strrindex_v2(char s[], char t[]) {
  int i, j, k;

  int res = -1;
  for (i = 0; s[i] != '\0'; ++i) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
      ;
    if (k > 0 && t[k] == '\0')
      res = i;
  }

  return res;
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
