#include <stdio.h>

/* 
 * count characters in input; 1st version
 */
int main1() {
  long nc;

  nc = 0;
  while (getchar() != EOF)
    // compare with nc = nc + 1, ++nc is more concise and often more efficient
    ++nc;
  // %ld tells printf that the corresponding argument is a long integer
  printf("%ld\n", nc);
}

/* 
 * count characters in input; 2st version
 */
int main() {
  // cope with even bigger numbers by using double
  double nc;

  for (nc = 0; getchar() != EOF; ++nc)
    ;
  printf("%.0f\n", nc);
}
