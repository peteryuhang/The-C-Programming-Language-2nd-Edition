#include <stdio.h>

#define MAXLINE 1000 // maximum input line size

int getlinestored(char line[], int maxline);

/* get the length of line, the purpose is for testing */
void reverse(char line[]);

/*
 * Write a function reverse(s) that reverse the character string s.
 * Use it to write a program that reverse its input a line at a time
 */
int main() {
  int len;
  char line[MAXLINE];     // current input line

  while ((len=getlinestored(line, MAXLINE)) >= 0) {
    if (len > 0) {
      reverse(line);
      printf("Line after reverse:  %s", line);
    }
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

  if (i > 0 && c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

/* 
 * reverse: reverse the input string
 */
void reverse(char s[]) {
  int i, j, tmp;
  for (i = 0; s[i] != '\0'; ++i)
    ;
  for (j = 0, i = i - 1; i > j; --i, ++j) {
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
}
