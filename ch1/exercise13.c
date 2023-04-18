#include <stdio.h>

/* Tips: press ctrl-d to give EOF and break the loop */

/* 
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical orientation
 * is more challenging
 */
#define IN  1      // inside a word
#define OUT 0      // outside a word

// horizontal
int main_h() {
  int c, i, wl, state;
  int lengths[300];
  
  for (i = 0; i < 300; ++i)
    lengths[i] = 0;

  state = OUT;
  wl = 0;

  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        ++lengths[wl];
        wl = 0;
      }
      state = OUT;
    } else {
      state = IN;
      ++wl;
    }

  printf("\n");
  int j;
  for (i = 0; i < 300; ++i)
    if (lengths[i] > 0) {
      printf("length = %3d: ", i);
      for (j = 0; j < lengths[i]; ++j)
        printf("%s", "#");
      printf("\n");
    }
}

// vertical
int main() {
  int c, i, wl, max, state;
  int lengths[300];
  
  for (i = 0; i < 300; ++i)
    lengths[i] = 0;

  state = OUT;
  wl = max = 0;

  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        ++lengths[wl];
        if (lengths[wl] > max) {
          max = lengths[wl];
        }
        wl = 0;
      }
      state = OUT;
    } else {
      state = IN;
      ++wl;
    }

  // print the head
  printf("\n");
  for (i = 0; i < 300; ++i)
    if (lengths[i] > 0)
      printf("%2d   ", i);
  printf("\n");
  printf("----------------------------------------\n");

  // print the histogram
  int j;
  for (i = max; i > 0; --i) {
    for (j = 0; j < 300; ++j) {
      if (lengths[j] == max) {
        printf("%2s   ", "#");
        --lengths[j];
      } else if (lengths[j] > 0) {
        printf("     ");
      }
    }
    printf("\n");
    --max;
  }
}