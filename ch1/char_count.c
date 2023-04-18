#include <stdio.h>


// Tips: press ctrl-d to give EOF and break the loop

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

  // all of the work is done in the test and increment parts
  // But the grammatical rules of C require that a for statement have a body
  // The isolated semicolon, called a null statement, is there to satisfy that requirement
  for (nc = 0; getchar() != EOF; ++nc)
    ;
  printf("%.0f\n", nc);
}
