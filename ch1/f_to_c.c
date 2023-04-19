#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300 */
int main() {
  // int fahr, celsius;
  
  float fahr, celsius; // float version

  int lower, upper, step;

  lower = 0;     // lower limit of temperature table
  upper = 300;   // upper limit
  step = 20;     // step size

  fahr = lower;
  while (fahr <= upper) {
    /* 
     * multiply 5 and then dividing 9 instead of multiplying by 5/9
     * because integer devision truncates and any fractional part is discarded
     * 5/9 will become zero, so the result will also be 0
     */
    // celsius = 5 * (fahr-32) / 9;
    
    // float version
    /* 
     * If an arithmetic operator has one floating-point operand and one integer operand
     * the integer will be converted to floating point before the operation is done
     * 
     * eg. 32 here will be automatically converted to floating point
     * 
     * but better to write 32 as 32.0 to emphasizes their floating-point nature for human reader
     */
    celsius = (5.0/9.0) * (fahr-32);

    /* 
     * printf is just a useful function from the standard library of
     * functions that are normally accessible to C programs
     * 
     * The behavior of printf is defined in the ANSI standard, however,
     * so its properties should be the same with any compiler and libaray
     * that conforms to the standard
     */
    // printf("%d\t%d\n", fahr, celsius);

    /* 
     * The numbers printed not right-justified, can give each the number with a width
     * 
     * eg. print the first number in a field three digits wide
     *               second number in a field six digits wide
     */
    // printf("%3d %6d\n", fahr, celsius);

    /* 
     * %3.0f says that a fahr is to be printed at least 3 character wide
     * with no decimal point and no fraction digits
     * 
     * %6.1f says that celsius is to be printed at least 6 character wide
     * with 1 digit after decimal point
     * 
     * some examples:
     * %d        print as decimal integer
     * %6d       print as decimal integer, at least 6 characters wide
     * %f        print as floating integer
     * %6f       print as decimal integer, at least 6 characters wide
     * %.2f      print as decimal integer, 2 characters after decimal point
     * %6.2f     print as decimal integer, at least 6 wide and 2 after decimal point
     * 
     * others:
     * %o for octal
     * %x for hexadecimal
     * %c for character
     * %s for character string
     * %% for % itsef
     */
    printf("%3.0f %8.1f\n", fahr, celsius);
    
    fahr = fahr + step;
  }
}