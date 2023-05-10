#include <stdio.h>

// echo command-line arguments: 1st version
// int main(int argc, char *argv[]) {
//   int i;

//   for (i = 1; i < argc; i++)
//     printf("%s%s", argv[i], (i < argc-1) ? " " : "");
//   printf("\n");
//   return 0;
// }

// echo command-line arguments: 2st version
int main(int argc, char *argv[]) {
  while (--argc > 0)
    printf("%s%s", *++argv, argc > 1 ? " " : "");
    // the format argument of printf can be an expression
    // printf((argc > 1) ? "%s " : "", *++argv);
  printf("\n");
  return 0;
}