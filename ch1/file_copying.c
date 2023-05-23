#include <stdio.h>

/* 
 * program that copies its input to its output one character at a time
 * 
 * read a character
 * while (character in not End-of-File indicator)
 *    output the character just read
 *    read a character
 */
int main() {
  int c;
  
  c = getchar();
  /* 
   * EOF is an integer defined in <stdio.h>, and it should big enough to hold EOF
   * in addition to any possible char. Therefore we use int
   */
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
}

int main2() {
  int c;
  
  /* 
   * - In C, an assignment can appear as part of a larger expression
   * - The assignment's value is the left hand side after the assignment
   * - The precedence of != is higher than that of =
   */
  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}
