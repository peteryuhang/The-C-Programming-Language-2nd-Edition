
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
- Function themselves are **always external**, because C does not allow functions to be defined inside other functions
- **External Linkage**: The standard that external variable and functions have the property that all references to them by the same name are references to the same thing
- The scope of an external variable or a function lasts from the point at which it is declared to the end of the file being compiled
  ```c
  main() {...}

  int sp = 0;
  double val[MAXVAL];

  void push(double f) {...}
  double pop(void) {...}
  ```
  - On above example, variable sp and val can be used in push and pop w/o declaration, but main need declaration before use them
- A declaration **announces the properties** of a variable; a definition also cause storage to be set aside
  - There must be only one **definition** of an external variable among all the files that make up the source program; other files may contain **extern** declarations to access it
  - **Array sizes** must be specified with definition, but are optional with an extern declaration
- **Static Variables**
  - The static declaration applied to an **external variable or function**, limits the scope of that object to the rest of the source file being compiled
  ```c
  static char buf[BUFSIZE];
  static int bufp = 0;
  ```
  - These **name will not conflict** with the same names in other files of the same program
  - Static can also been used for **internal variable**. Internal static variable provide private, permanent storage within a single function