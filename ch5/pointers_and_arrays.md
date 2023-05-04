- **Some example usages of pointers**
  ```c
  int x = 1, y = 2, z[10];
  int *ip;                  // ip is a pointer to int
  ip = &x;                  // ip now points to x
  y = *ip;                  // y is now 1
  *ip = 0;                  // x is now 0
  ip = &z[0]                // ip now points to z[0]
  ++*ip;

  /*
   * The parenthese are necessary for case below, because unary operator like * and ++
   * associate right to left
   */
  (*ip)++;
  ```
  - `int *ip` says that the expression `*ip` is an int
  - `p = &c` p is said to "point to"  c
  - `iq = ip` making iq point to whatever ip pointed to
