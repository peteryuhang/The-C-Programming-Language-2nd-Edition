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

