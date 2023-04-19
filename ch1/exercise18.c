#include <stdio.h>

#define MAXLINE 1000 // maximum input line size

int getlinestored(char line[], int maxline);

/* get the length of line, the purpose is for testing */
int getlinelength(char line[], int maxline);

/*
 * Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines
 */
int main() {
  int len;                // current line length
  char line[MAXLINE];     // current input line

  while ((len = getlinestored(line, MAXLINE)) >= 0) {
    // for testing & verify only
    // printf("The length after remove trailing: %d\n", getlinelength(line, MAXLINE));
    if (len > 0)
      printf("%s", line);
  }
  return 0;
}

/*
 * getlinestored: Read line into s, return length 
 */
int getlinestored(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  // for testing & verify only
  // s[i] = '\0';
  // printf("The length before remove trailing: %d\n", getlinelength(s, MAXLINE) + 1);
  // s[i] = 0;

  // remove the trailing blanks & tabs from current line
  for (; i > 0 && (s[i - 1] == '\t' || s[i - 1] == ' '); --i)
    ;

  if (i > 0 && c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

/* 
 * getlinelength: get the length of input string
 */
int getlinelength(char s[], int lim) {
  int i;
  for (i = 0; i < lim && s[i] != '\0'; ++i)
    ;
  return i;
}
