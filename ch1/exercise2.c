#include <stdio.h>


// warning gave:
// exercise2.c:4:18: warning: unknown escape sequence '\c' [-Wunknown-escape-sequence]
int main() {
  printf("hello, \c world\n");
}

// output:
// hello, c world