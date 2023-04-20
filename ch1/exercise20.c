#include <stdio.h>

/* 
 * Write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, says
 * every n columns. Should n be a variable or a symbolic parameter?
 */
#define TAB_SIZE 8

/* 
 * The tab strategy: will increase space(s) to the next pos which can divided by TAB_SIZE
 *
 * eg. if \t at column 6, then \t will make cursor goto column 9
 * 
 * Use formula below for calculating the number of space
 *    (TAB_SIZE - p % TAB_SIZE) % TAB_SIZE + 1
 * 
 * formula explain in detail:
 * - p represents current curson position (start from 1)
 * - (p % TAB_SIZE) represents the distance from the start of current tab size
 * - (TAB_SIZE - p % TAB_SIZE) represents the distance to the end of current tab
 *    but p = n * TAB_SIZE is a exception, which means cursor on the end pos of current tab
 * - (TAB_SIZE - p % TAB_SIZE) % TAB_SIZE try to resolve current cursor stop on end of tab
 */
int main() {
  int c, i, p, nbs;

  p = 1;
  while ((c=getchar()) != EOF) {
    if (c == '\t') {
      nbs = (TAB_SIZE - p % TAB_SIZE) % TAB_SIZE + 1;
      for (i = 0; i < nbs; ++i) {
        putchar(' ');
      }
      p += nbs;
    } else if (c == '\n') {
      putchar(c);
      p = 1;
    } else {
      ++p;
      putchar(c);
    }
  }
}
