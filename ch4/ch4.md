
- If the **return type is omitted**, int is assumed
- a minimal function is `dummy() {}`
  - this function does nothing and return nothing, sometime useful **as a place holder** during program development
- The returned expression will be converted to returned type of the function if necessary
- The function can be declared in the function, eg.
  ```c
  #include <stdio.h>

  #define MAXLINE 100

  int main() {
    double sum, atof(char[]);
    char line[MAXLINE];
    int getline(char line[], int max);

    sum = 0;
    while (getline(line, MAXLINE) > 0)
      printf("\t%g\n", sum += atof(line));
    return 0;
  }
  ```
  - Function must been declared and defined **consistently**. Otherwise some potential issue might not been detected even by compiler
  - Declaration is necessary, otherwise it will be decided by the context to be a function name, which could make potential bug or issue
  - If the function takes arguments, declare them; if it takes no arguments, use **void**. Because empty list just mean that nothing is to be assumed about the arguments of function; all parameter checking is turned off