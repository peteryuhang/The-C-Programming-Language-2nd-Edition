#include <stdio.h>

/* 
 * Write a program entab that replaces strings of blanks by the minimum number of
 * tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
 * When either a tab or a single blank would suffice to reach a tab stop, which should
 * be given preference?
 * 
 * Answer for last question: space. Because it can potentially be more consistent compare with tab
 */
#define TAB_SIZE 8

int main() {
  int nb, nt, p, c;

  nb = nt = 0;

  for (p = 1; (c = getchar()) != EOF; ++p)
    if (c == ' ') {
      if ((p % TAB_SIZE) != 0)
        ++nb;
      else {
        nb = 0;
        ++nt;
      }
    } else {
      for (; nt > 0; --nt)
        putchar('\t');
      if (c == '\t')
        nb = 0;
      else
        for (; nb > 0; --nb)
          putchar(' ');

      putchar(c);

      if (c == '\n')
        p = 0;
      else if (c == '\t')
        /*
         * p                                    -> position of current cursor but w/o consider expanding of current '\t'
         * (p - 1)                              -> previous character's position
         * (p - 1) % TAB_SIZE                   -> space of character(s) which occupy current '\t'
         * TAB_SIZE - (p - 1) % TAB_SIZE        -> position need to added if consider current '\t'
         * TAB_SIZE - (p - 1) % TAB_SIZE - 1    -> same as above, but for loop will increase 1 in the end, so just subtract it
         */
        p += (TAB_SIZE - (p - 1) % TAB_SIZE) - 1;
    }

  return 0;
}