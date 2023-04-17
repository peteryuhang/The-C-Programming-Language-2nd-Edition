#include <stdio.h>

/*
 * Modify the temperature conversion program(f_to_c.c) to print a heading above the table
 */
int main() {
  float fahr, celsius;

  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  // print the heading
  printf("%3s %6s\n", "f", "c");

  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32);

    printf("%3.0f %6.1f\n", fahr, celsius);
    
    fahr = fahr + step;
  }
}