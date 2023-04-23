#include <stdio.h>

/* 
 * Write a loop equivalent to the for loop below without using && or ||
 * 
 * for (i = 0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *   s[i] = c;
 */
int main() {
  int c, i, lim;
  char s[100];

  lim = 9999;
  for (i = 0; i<lim-1; ++i) {
    if ((c=getchar()) == '\n') {
      break;
    }

    if (c == EOF) {
      break;
    }

    s[i] = c;
  }
}