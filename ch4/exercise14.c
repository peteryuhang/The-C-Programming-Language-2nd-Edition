#include <stdio.h>

/* 
 * Define a macro swap(t,x,y) that interchanges two arguments of type t
 * (Block structure will help)
 */
#define swap(t,x,y) { t tmp; tmp = x; x = y; y = tmp; }

int main() {
  int x = 0, y = 1;
  swap(int, x, y);

  printf("x = %d, y = %d\n", x, y);
}
