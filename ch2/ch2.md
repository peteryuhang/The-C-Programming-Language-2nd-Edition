## Types & Variables

- Don't begin variable names with underscore, however, since library routinue often use such names
- Unsigned constants are written with a terminal `u` or `U`, and the suffix `ul` or `UL` indicates unsigned long
- The suffixes `f` or `F` indicate a float constant
- The character constant `'\0'` represents the character with value zero, the **null character**. The **numeric value** is just 0
- String constants can be concatenated at compile time:
  ```c
  "hello, " "world"
  is equivalent to
  "hello, world"
  ```
- A string constant is an array of characters, the length of string can be got by:
  ```c
  /* strlen: return length of s */
  int strlen(char s[]) {
    int i;

    i = 0;
    while (s[i] != '\0')
      ++i;
    return i;
  }
  ```
  - `strlen` and other string functions are declared in the standard header `<string.h>`
  - `'x'` is not the same as `"x"`. The former is an integer, the latter is an array that contains one character and a '\0'
- **enumeration constant**
  ```c
  // the first name in an enum has value 0, the next 1 and so on
  enum boolean { NO, YES };

  /*
   * If not all values are specified, unspecified values continue the progression from
   * the last specified value
   */
  enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
                 NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
  enum months { JAN = 1, FEB, MAR, APR, MAY, JUN
                JUL, AUG, SEP, OCT, NOV, DEC }; /* FEB is 2, MAR is 3, etc. */
  ```
- For an array, the const qualifier says that the elements will not be altered

## Operators
- Precedence of operator (from **higher to lower**)
  - ! ~ \+ \- (unary)
  - \* / % 
  - \+ \- (binary)
  - << >>
  - \> >= < <=
  - == !=
  - &
  - ^
  - |
  - &&
  - ||
  - ?:
  - =
  - ,
- In general, the only **automatic conversions** are those that **convert a "narrower" operand into a "wider"** one without losing information
  ```c
  /* atoi: convert s to integer */
  int atoi(char s[]) {
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
      n = 10 * n + (s[i] - '0');
    return n;
  }

  /* lower: convert c to lower case; ASCII only */
  int lower(int c) {
    if (c >= 'A' && c <= 'Z')
      return c + 'a' - 'A';
    return c;
  }
  ```
  - If arguments are declared by a function prototype, as they normally should be, the declaration causes automatic coercion of any arguments when the fuction is called
- The expression `++n` increments n **before** its value is used, while `n++` increments n **after** its value has been used
- The increment and decrement operators can only be appiled to variables; `(i+j)++` is illegal
- **Bitwise Operators**
  ```
  &      bitwise AND
  |      bitwise inclusive OR
  ^      bitwise exclusive OR
  <<     left shift
  >>     right shift
  ~      one's complement (unary)
  ```
  - `&` is often used to mask off some set of bits
  - `|` is often used to turn bits on
  - Right shifting an **unsigned** quantity always fills vacated bits with 0
  - Right shifting a signed quantity will fill with sign bits **("arithmetic shift")** on some machines and with 0-bits **("logic shift")** on others
  - The portable form (`x & ~077`) involves no extra cost, since `~077` is a constant expression that can be evaluated at **compile time**
  - `getbits(x,p,n)`
    ```c
    /* 
     * getbits: get n bits from position p
     * 
     * assuming the position start at the right end and that n and p are sensible positive values
     * 
     * eg. getbits(x,4,3) for 76543210 will return 432
     */
    unsigned getbits(unsigned x, int p, int n) {
      return (x >> (p+1-n)) & ~(~0 << n);
    }
    ```
