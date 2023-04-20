#include <stdio.h>

#define MAXLINE 1000    // maximum input line size

/* 
 * - If the definition of an external variable occurs in the source file before its
 * use in a particular function, then the extern declarations can be omit
 * 
 * - In fact, common practice is to place definitions of all external variable at the
 * beginning of the source file, and then omit all extern declarations
 * 
 * - An external variable must be defined, exactly once, outside of any function;
 * this set aside storage for it
 * 
 * - The external variable must also be declared in each function that wants to access it;
 * this states the type of the variable
 * 
 * - "definition" refers to where the variable is created or assigned storage
 *   "declaration" refers to places where the nature of the variable is stated but no storage is allocated
 */
int max;                // maximum length seen so far
char line[MAXLINE];     // current input line
char longest[MAXLINE];  // longest line save here

/* For compatibility with older C programs, the word void must be used for an explicitly empty list */
int getlinestored(void);
void copy(void);

int main() {
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getlinestored()) > 0)
    if (len > max) {
      max = len;
      copy();
    }
  if (max > 0)      // there was a line
    printf("%s", longest);
  return 0;
}

/*
 * getlinestored: specialized version 
 */
int getlinestored(void) {
  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  
  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

/* 
 * copy: specialized version
 */
void copy(void) {
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}
