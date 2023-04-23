#include <stdio.h>

/* 
 * Write the function setbits(x,p,n,y) that returns x with the n bits
 * that begin at position p set the rightmost n bits of y, leaving the
 * other bits unchanged
 * 
 * eg. assuming input: x = X7X6X5X4X3X2X1X0, p = 4, n = 3, y = Y7Y6Y5Y4Y3Y2Y1Y0
 *     expected output: X7X6X5  Y2Y1Y0  X1X0
 */
int setbits(unsigned x, int p, int n, unsigned y);

int main() {
  printf("The output for setbits(12, 3, 2, 57) is %u\n", setbits((unsigned)12, 3, 2, (unsigned)57));
}

int setbits(unsigned x, int p, int n, unsigned y) {
  /*
   * input: x = X7X6X5X4X3X2X1X0, p = 4, n = 3, y = Y7Y6Y5Y4Y3Y2Y1Y0
   *
   * ((~0 << p+1) & x) represents:                      X7X6X5....
   * ((~(~0 << n) & y) << (p+1-n)) represents:             ...Y2Y1Y0...
   * (~(~0 << (p+1-n)) & x) represents:                          ...X1X0
   * 
   * ... means 0, so apply inclusive OR for 3 formula above can get what we expected
   * 
   * real case: x = 12 (00001100), p = 3, n = 2, y = 57 (00111001)
   * 
   *    x           y                 result
   * 00001100    00111001           0000 01 00 
   * 76543210    76543210           7654 32 10
   * 
   * ((~0 << 4) & 00001100) represents:                      00000000
   * ((~(~0 << 2) & 00111001) << (3+1-2)) represents:        00000100
   * (~(~0 << (3+1-2)) & 00001100) represents:               00000000
   */
  return ((~0 << (p+1)) & x) | ((~(~0 << n) & y) << (p+1-n)) | (~(~0 << (p+1-n)) & x);
}