#include <stdio.h>

/* 
 * Write the function rightrot(x,n) that returns the value of the integer x
 * rotated to the right by n bit positions
 */
unsigned rightrot(unsigned x, int n);

int main() {
  printf("The output for rightrot(7, 35) is %u\n", rightrot(7, 35));
}

unsigned rightrot(unsigned x, int n) {
  /*
   * 12345678
   * 56781234        -> 00001234 | 56780000
   */
  int nbits;

  nbits = sizeof(x) * 8;
  return (x >> (n % nbits)) | (x << (nbits - n % nbits));
}