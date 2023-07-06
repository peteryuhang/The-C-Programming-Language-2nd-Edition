#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int c, (*convert)(int) = NULL;

  if (strcmp(argv[0], "lower") == 0) {
    convert = tolower;
  }

  if (strcmp(argv[0], "upper") == 0) {
    convert = toupper;
  }

  while ((c = getchar()) != EOF) 
    putchar((*convert)(c));

  return 0;
}