#include <stdio.h>

/* Tips: press ctrl-d to give EOF and break the loop */

/* 
 * count lines in input
 */
int main() {
  int c, nl;

  nl = 0;
  while ((c = getchar()) != EOF)
    /* 
     * character constant: another way to write a small integer
     *
     * '\n' stands for the value of the newline character, which is 10 in ASCII
     */
    if (c == '\n')
      ++nl;
  printf("%d\n", nl);
}