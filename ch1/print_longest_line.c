#include <stdio.h>

#define MAXLINE 1000 // maximum input line size

/* Rename getline to getlinestored to resolve name conflict with getline inside stdio.h */
int getlinestored(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;                // current line length
  int max;                // maximum length seen so far
  char line[MAXLINE];     // current input line
  char longest[MAXLINE];  // longest line save here

  max = 0;
  /* 
   * There is no way for a user of getline to know in advance how long an
   * input line might be, so getline checks for overflow
   * 
   * On the other hand, the user of copy already knows how big the strings are,
   * so we have chosen not to add error checking to it
   */
  while ((len = getlinestored(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)      // there was a line
    /* %s format specification expects the char array with \0 marked for ending */
    printf("%s", longest);
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

  /* 
   * put the character '\0' (null character) at the end of the array it is creating
   * to mark the end of the string of characters
   */
  s[i] = '\0';

  return i;
}

/* 
 * copy: copy 'from' into 'to'; assume to is big enough
 */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
