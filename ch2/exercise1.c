#include <stdio.h>
#include <limits.h>
#include <float.h>


/* 
 * Write a program to determine the ranges of char, short, int, and long variables,
 * both signed and unsigned, by printing appropriate value from standard headers and
 * by direct computation. Harder if you compute them: determine the ranges of the
 * various floating-point types
 */
void print_from_standard();
void direct_computation();


int main() {
  print_from_standard();
  direct_computation();
}

void print_from_standard() {
  printf("Determine the range of integer type from standard headers:\n");

  printf("Range of signed char [%d, %d]\n", CHAR_MIN, CHAR_MAX);
  printf("Range of unsigned char [%u, %u]\n", 0, UCHAR_MAX);

  printf("Range of signed short [%d, %d]\n", SHRT_MIN, SHRT_MAX);
  printf("Range of unsigned short [%u, %u]\n", 0, USHRT_MAX);

  printf("Range of signed int [%d, %d]\n", INT_MIN, INT_MAX);
  printf("Range of unsigned int [%u, %u]\n", 0, UINT_MAX);

  printf("Range of signed long [%ld, %ld]\n", LONG_MIN, LONG_MAX);
  printf("Range of unsigned long [%lu, %lu]\n\n\n", 0L, ULONG_MAX);
}

void direct_computation() {
  printf("Determine the range of integer type by calculation:\n");

  printf("Range of signed char [%d, %d]\n", 
    -(char)((unsigned char)~0 >> 1) - 1, (char)((unsigned char)~0 >> 1));
  printf("Range of unsigned char [%u, %u]\n",
    0, (unsigned char)~0);

  printf("Range of signed short [%d, %d]\n",
    -(short)((unsigned short)~0 >> 1) - 1, (short)((unsigned short)~0 >> 1));
  printf("Range of unsigned short [%u, %u]\n",
    0, (unsigned short)~0);

  printf("Range of signed int [%d, %d]\n",
    -(int)((unsigned int)~0 >> 1) - 1, (int)((unsigned int)~0 >> 1));
  printf("Range of unsigned int [%u, %u]\n",
    0, (unsigned int)~0);

  printf("Range of signed long [%ld, %ld]\n",
    -(long)((unsigned long)~0 >> 1) - 1, (long)((unsigned long)~0 >> 1));
  printf("Range of unsigned long [%lu, %lu]\n",
    0L, (unsigned long)~0);
}
