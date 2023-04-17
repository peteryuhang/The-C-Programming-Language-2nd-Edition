#include <stdio.h>


/* 
 * A #define line defines a symbolic name or symbolic constant to be a
 * particular string of character
 *
 * the format:
 * #define name replacement_text
 * 
 * Symbolic constant names are conventionally written in upper case so they
 * can be readily distinguished from lower case variable names
 * 
 * Notice that there is no semicolon at the end of a #define line
 */
#define LOWER 0        // lower limit of table
#define UPPER 300      // upper limit
#define STEP  20       // step size

/*
 * print Fahrenheit-Celsius table
 */
int main() {
  int fahr;

  for (fahr = 0; fahr <= 300; fahr = fahr + 20)
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}