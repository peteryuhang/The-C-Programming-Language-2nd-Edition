#include <stdio.h>

#define MAXLINE 1000    // maximum input line size
#define PRINT_LENTH 80  // threshold for printing line

int getlinestored(char line[], int maxline);

/* 
 * Write a program to print all input lines that are longer than 80 characters
 */
int main() {
  int len;                // current line length
  char line[MAXLINE];     // current input line

  while ((len = getlinestored(line, MAXLINE)) > 0)
    // print all lines that are longer than 80 characters
    if (len > PRINT_LENTH)
      printf("%s", line);
  return 0;
}

/*
 * getlinestored: Read line into s, return length 
 */
int getlinestored(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  
  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}
