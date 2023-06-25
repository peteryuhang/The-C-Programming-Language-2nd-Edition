## Basic of structure

- A `struct` declaration defines a type, eg:
  ```c
  struct point {
    int x;
    int y;
  };
  ```
- The right brace that terminates the list of members may be followed by a list of variables, just as for any basic type, eg:
  ```c
  struct { ... } x, y, z;
  ```
  - This is syntactically analogous to `int x, y, z;`
  - A structure declaration that is not followed by a list of variables **reserves no storage**; it merely describes a template or the shape of a structure
- If the declaration is tagged, however, the tag can be used later in definitions of instances of the structure, eg:
  ```c
  struct point pt;
  ```
- A structure can be initialized by following its definition with a list of initializers, eg:
  ```c
  struct point pt = { 320, 200 };
  ```

## Structures and Functions

- Structures may not be compared
- If a large structure is to be passed to a function, it is generally more efficient to pass a pointer than to copy the whole structure, eg.
  ```c
  struct point origin, *pp;
  pp = &origin;
  printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);
  ```
  - The parenthese are necessary in `(*pp).x` because precedence of the structure member operator `.` is higher than `*`, `*pp.x` means `*(pp.x)` which is illegal
  - An alternative shorthand was `p->member-of-structure`
  ```c
  printf("origin is (%d,%d)\n", pp->x, pp->y);
  ```
  - Both `.` and `->` associate from **left to right**
- The structure operator `.` and `->`, together with `()` for function calls and `[]` for subscripts, are at top of the precedence hierarchy and thus bind very tightly, some example
  ```c
  // increments len not p
  ++p->len;
  // fetch whatever str points to
  *p->str;
  // increments str after accessing whatever it points to
  *p->str++;
  // increments whatever str points to
  (*p->str)++;
  // increments p after accessing whatever str points to
  *p++->str;
  ```

## Arrays of Structures

- C provides a compile-time unary operator called **sizeof** that can be used to compute the size of any object or type, syntax below
  ```c
  sizeof object
  sizeof(type name)
  ```
  - **sizeof** can not be used in a `#if` line, because the preprocessor does not parse type names
  - The expression in the `#define` is not evaluated by the preprocessor, so **sizeof** is legal there