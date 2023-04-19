#include <stdio.h>

/* 
 * - With properly designed functions, it is possible to ignore how a job is done;
 * knowing what is done is sufficient
 * - This declaration, which is called a function prototype, has to agree with the
 * definition and uses of power
 * - parameter names are optional in a function prototype, so it can also been written as:
 *      int power(int, int);
 */
int power(int m, int n);

/* test power function */
int main() {
  int i;

  for (i = 0; i < 10; ++i)
    printf("%d %d %d\n", i, power(2,i), power(-3,i));
  
  /*
   * main can return status to its execute environment. Typically,
   * a return value of zero implies normal termination; non-zero values
   * signal unusual or erroneous termination conditions
   */
  return 0;
}

/* power: raise base to n-th power; n >=0 */
/* 
 * - We will generally use parameter for a variable named in the parenthesized
 * list in a function definition, and argument for the value used in a call of the
 * function. The term formal argument and actual argument are sometimes used for
 * the same distinction
 */
int power(int base, int n) {
  int i, p;

  p = 1;
  for (i = 1; i <= n; ++i)
    p = p * base;
  return p;
}