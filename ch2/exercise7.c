#include <stdio.h>

/* 
 * Write the function invert(x,p,n) that returns x with the n bits that
 * begin at position p inverted (i.e. 1 changed into 0 and vice versa), leaving
 * the others unchanged
 */
int invert(unsigned x, int p, int n);

int main() {
  printf("The output for invert(8, 3, 3) is %u\n", invert((unsigned)8, 3, 3));
}

int invert(unsigned x, int p, int n) {
  /*
   * 
   * same as setbits(x, p, n, ~x)
   */
  // return ((~0 << (p+1)) & x) | ((~(~0 << (p+1-n)) & (x >> (p+1-n))) << (p+1-n)) | (~(~0 << (p+1-n)) & x);

  /* 
   * x ^ (~(~0 << n) << (p+1-n))
   *
   * ~(~0 << n) represents:                                 ...111 
   * ~(~0 << n) represents:                                 ...111
   * (~(~0 << n) << (p+1-n)) represents:                 ...111...
   */
  return x ^ ((~(~0 << n) << (p+1-n)));
}