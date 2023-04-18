#include <stdio.h>

/* Tips: press ctrl-d to give EOF and break the loop */

/* 
 * Write a program to print a histogram of the lengths of the frequencies of
 * different characters in its input
 */
int main() {
  int c, i;
  int freqs[256];

  for (i = 0; i < 256; ++i)
    freqs[i] = 0;

  while ((c = getchar()) != EOF)
    ++freqs[c];

  printf("\n");
  int j;
  for (i = 0; i < 256; ++i)
    if (freqs[i] > 0) {
      if (i == '\t')
        printf("char = %c%c: ", '\\', 't');
      else if (i == '\n')
        printf("char = %c%c: ", '\\', 'n');
      else if (i == ' ') 
        printf("char = %c%c: ", '\\', 'w');
      else
        printf("char = %2c: ", i);
      for (j = 0; j < freqs[i]; ++j)
        printf("%s", "#");
      printf("\n");
    }
}