#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

double atofe(char t[]);

/* 
 * Extend atof to handle scientific notation of the form
 *          123.45e-6
 * where a floating-point number may be followed by e or E and an optionally signed exponent
 */
int main() {
  printf("%0.9f\n", atofe("123.45e-6"));
  printf("%0.9f\n", atofe("123.45e6"));
  printf("%0.9f\n", atofe("123"));
  printf("%0.9f\n", atofe("-123.45E-6"));
  printf("%0.9lf\n", atofe("123.45E+1"));
}

/* atof: convert string s to double */
// double atof(char s[]) {
//   double val, power;
//   int i, sign;

//   for (i = 0; isspace(s[i]); ++i)  /* skip the white space */
//     ;
//   sign = (s[i] == '-') ? -1 : 1;
//   if (s[i] == '+' || s[i] == '-')
//     ++i;
//   for (val = 0.0; isdigit(s[i]); ++i)
//     val = 10.0 * val + (s[i] - '0');
//   if (s[i] == '.')
//     ++i;
//   for (power = 1.0; isdigit(s[i]); ++i) {
//     val = 10.0 * val + (s[i] - '0');
//     power *= 10.0;
//   }
//   return sign * val / power;
// }

/* atofe: convert string s to double, can handle scientific notation */
double atofe(char s[]) {
  double val, power, e;
  int i, sign, e_sign;

  for (i = 0; isspace(s[i]); ++i)  /* skip the white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    ++i;

  for (val = 0.0; isdigit(s[i]); ++i)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.')
    ++i;

  for (power = 1.0; isdigit(s[i]); ++i) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  if (s[i] == 'e' || s[i] == 'E') {
    ++i;

    e_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
      ++i;

    for (e = 0; isdigit(s[i]); ++i)
      e = 10 * e + (s[i] - '0');
    
    int j;
    for (j = 0; j < e; ++j)
      if (e_sign < 0)
        power *= 10.0;
      else
        power /= 10.0;
  }

  return sign * val / power;
}

