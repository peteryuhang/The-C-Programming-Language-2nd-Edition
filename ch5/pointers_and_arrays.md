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
- **Pointers and Arrays**
  - If `pa` points to `a[0]`, `*(pa+1)` refers to the contents `a[1]`
    - `pa+i` is the **address** of `a[i]`
    - `*(pa+i)` is the **content** of `a[i]`
    - The meaning of **"adding 1 to a pointer"**, and by extension, all pointer arithmetic, is that `pa+1` points to the next object, and `pa+i` points to the i-th object beyond `pa`
  - By definition, the value of a variable or expression of type array is the address of element zero of the array
    - `pa = &a[0]` can also be written as `pa = a`; `&a[i]` and `a+i` are also identical
    - In evaluating `a[i]`, C convert it to `*(a+i)` immediately, the two forms are equivalent
  - The one **differece** between an array name and a pointer:
    - A pointer is a **variable**, so `pa=a` and `pa++` are **legal**. But an array name is **not a variable**; constructions like `a=pa` and `a++` are **illegal**
  - When an array name is passed to a function, what is passed is the location of the initial element:
    ```c
    /* strlen: return length of string s */
    int strlen(char *s) {
      int n;

      for (n = 0; *s != '\0'; s++)
        n++;
      return n;
    }

    // following statement are legal
    strlen("hello world");       /* string constant */
    strlen(array);               /* char array[100]; */
    strlen(ptr);                 /* char *ptr; */
    ```
  - It is possible to pass **part of an array** to a function, by passing a pointer to the beginning of the subarray
    - eg. `f(&a[2])` or `f(a+2)` pass the address of **subarray** that starts at `a[2]`, within `f`, the parameter declaration can read `f(int arr[]) {...}` or `f(int *arr) {...}`
    - If one is sure that the element exist, it is also possible to index backwards in an array; `a[-1]`, `a[-2]` are **legal**. It is **illegal** to ref to objects that are not within the array bounds
  - If `p` and `q` point to members of the same array, then relations like `==`, `!=`, `<`, `>=`, etc., work properly
    ```c
    /*
     * strlen: return length of string s 
     *
     * if cautious, we would size_t for the return type,
     * size_t is the unsigned integer type returned by the sizeof operator
     */
    int strlen(char *s) {
      char *p = s;

      while (*p != '\0')
        p++;
      return p - s;
    }
    ```
  - C guarantees that **zero is never a valid address for data**, so a return value of zero can be used to signal an abnormal event. The constant zero may be assigned to a pointer, and a pointer may be compared with the constant zero
    - The symbolic constant **NULL** (defined in <studio.h>) is often used in place of zero, as a mnemonic to indicate more clearly that this is a special value for a pointer
  - All the pointer manipulations automatically take into account the size of the object pointed to
  - **Valid pointer operations**
    - Assignment of pointers of the same type
    - Adding or subtracting a pointer and an integer
    - Subtracting or comparing two pointer to member of the same array
    - Assigning or comparing to zero
  - There is an important difference between below 2 statements:
    ```c
    char amsg[] = "pointer and array";  /* an array */
    char *pmsg = "pointer and array";   /* a pointer */
    ```
    - Individual characters within the array may be changed but amsg will always refer to the same storage
    - pmsg is a pointer initialized to point to **a string constant**; the pointer may subsequently be modified to point elsewhere, but the result is undefined if you try to modify the string constants
  - `++` and `--` usage on pointer
    ```c
    *p++ = val;   /* push val onto stack */
    val = *--p;   /* pop top of stack into val */
    ```
  
