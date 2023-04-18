#include <stdio.h>

/* Tips: press ctrl-d to give EOF and break the loop */

/* 
 * Write a program to count blanks, tabs, and newlines
 */
int main() {
  int c, c_cnt;

  c_cnt = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\t' || c == '\n')
      ++c_cnt;
  printf("%d\n", c_cnt);
}
