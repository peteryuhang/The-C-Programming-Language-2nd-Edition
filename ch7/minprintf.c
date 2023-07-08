#include <stdio.h>
#include <stdarg.h>


void minprintf(char *fmt, ...);

int main() {
  minprintf("%d %s\n", 1, "pppp");
  minprintf("%f %s\n", 1.0, "pppp");
  minprintf("%e %s\n", "aaa", "pppp");
}

// minprintf: minimal printf with variable argument list
void minprintf(char *fmt, ...) {
  va_list ap;    // points to each unnamed arg in turn
  char *p, *sval;
  int ival;
  double dval;

  va_start(ap, fmt);  // make ap point to 1st unnamed arg
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch (*++p)
    {
    case 'd':
      ival = va_arg(ap, int);
      printf("%d", ival);
      break;
    case 'f':
      ival = va_arg(ap, double);
      printf("%f", dval);
      break;
    case 's':
      for (sval = va_arg(ap, char *); *sval; sval++)
        putchar(*sval);
      break;
    default:
      putchar(*p);
      break;
    }
  }
  va_end(ap);      // clean up when done
}