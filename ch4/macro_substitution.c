#include <stdio.h>


#define forever for (;;)    // infinite loop
#define max(A, B) ((A) > (B) ? (A) : (B))

/* 
 * the below format is wrong, because marco just text replacement
 * square_wrong(x+1) will be replaced as x+1 * x+1
 */
#define square_wrong(x) x * x
#define square(x) (x) * (x)

// Names may be undefined with #undef, usually to ensure that a routine
// is really a function, not a macro
#undef square_wrong

/* 
 * A parameter name is preceded by # in the replacement text, the combination
 * will be expanded into a quoted string with the parameter replaced by the
 * actual argument
 */
#define dprint(expr) printf(#expr " = %g\n", expr)


/* 
 * ## provide a way to concatenate actual argument during macro expansion
 * If a parameter in the replacement text is adjacent to a ##, the parameter
 * is replaced by the actual argument, the ## and surrounding white space are
 * removed
 */
#define paste(front, back) front ## back

/* 
 * The provides a way to include code selectively, depending on the value of conditions
 * evaluated during compilation
 */
#if !defined(forever)  // #ifndef forever   do the same thing 
#define forever while(true) {}
#endif


int main() {
  int m1 = 0, n1 = 1;
  // output 3, because the expression are evaluated twice
  printf("%d\n", max(m1, ++n1));

  int m2 = 0, n2 = 1;
  printf("%d\n", square(n2+1));

  double m3 = 5.1, n3 = 8.7;
  dprint(m3/n3);
}