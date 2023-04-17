#include <stdio.h>

/*
 * Write a program to print the corresponding Celsius to Fahrenheit table
 */
int main() {
  float fahr, celsius;

  int lower, upper, step;

  lower = 0;
  upper = 200;
  step = 10;

  fahr = lower;

  // print the heading
  printf("%3s %6s\n", "c", "f");

  while (celsius <= upper) {
    fahr = (9.0/5.0) * celsius + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}