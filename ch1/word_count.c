#include <stdio.h>

/* Tips: press ctrl-d to give EOF and break the loop */

#define IN  1      // inside a word
#define OUT 0      // outside a word

/* count lines, words, and characters in input */
int main() {
  int c, nl, nw, nc, state;
  
  /* 
   * The variable state records whether the program is currently in a word or not
   */
  state = OUT;

  /* 
   * This is not a special case, but a consequence of the fact that an assignment is an 
   * expression with a value and assignments associate from right to left
   * 
   * It is as if we had written
   * 
   * nl = (nw = (nc = 0));
   */
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    
    /* 
     * - There is a corresponding operator && for AND; its precedence is just higher than ||
     * - Expression connected by && or || are evaluated left to right
     * - It is guaranteed that evaluation will stop as soon as the truth or falsehood is known
     */
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
}