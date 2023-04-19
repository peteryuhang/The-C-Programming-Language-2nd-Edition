#include <stdio.h>

/* 
 * Rewrite the temperature conversion program of Section 1.2 to use
 * a function for conversion
 */
float f_to_c(float);

int main() {  
  float fahr, celsius; // float version

  int lower, upper, step;

  lower = 0;     // lower limit of temperature table
  upper = 300;   // upper limit
  step = 20;     // step size

  fahr = lower;
  while (fahr <= upper) {
    celsius = f_to_c(fahr);

    printf("%3.0f %8.1f\n", fahr, celsius);

    fahr = fahr + step;
  }
}

float f_to_c(float fahr) {
  return (5.0/9.0) * (fahr-32);
}
