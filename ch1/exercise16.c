#include <stdio.h>

#define MAXLINE 1000 // maximum input line size

int getlinestored(char line[], int maxline);
void copy(char to[], char from[]);

/* 
 * Revise the main routine of the longest-line program so it will
 * correctly print the length of arbitrarily long input lines, and
 * as much as possible of the text
 */
int main() {
  int len;                // current line length
  int max;                // maximum length seen so far
  char line[MAXLINE];     // current input line
  char longest[MAXLINE];  // longest line save here

  max = 0;
  while ((len = getlinestored(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }

  if (max > 0)
    printf("\n");
    printf("The longest line have %d characters, only display the first %d\n",
      max, MAXLINE);
    printf("%s", longest);
  return 0;
}

/* mainly change getlinestored to caculate actually length instead of max(lim, len) */
int getlinestored(char s[], int lim) {
  int c, i;

  for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i) {
    if (i < lim - 1)
      s[i] = c;
  }
  
  if (i < lim - 1 && c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
