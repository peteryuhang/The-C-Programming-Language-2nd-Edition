#include <stdio.h>

/* 
 * In a two's complement number system, x &= (x - 1) deletes the rightmost
 * 1-bit in x. Explain why. Use this observation to write a faster version
 * of bitcount
 * 
 * Explain:
 *    assume one integer x is xxx1...  (x means unkown, . means 0)
 *    so the value of x - 1 is xxx0111
 *    x &= (x - 1) can be written as thing below
 *       x = xxx1... & xxx0111
 *    so the final value of x is xxx0...
 */
int bitcount(unsigned x);

int main() {
  printf("The output for bitcount(7) is %u\n", bitcount(7));
}

int bitcount(unsigned x) {
  int i;
  for (i = 0; x > 0; x &= x - 1)
    ++i;
  return i;
}