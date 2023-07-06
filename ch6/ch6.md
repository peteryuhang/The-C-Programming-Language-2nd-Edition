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
- Don't assume that the size of a structure is the sum of the sizes of its members. Because of alignment requirement for different objects, there may be unnamed "holes" in a structure. eg.
  ```c
  struct {
    char c;
    int i;
  }
  ```
  - struct above will require eight bytes, not five. The `sizeof` operator returns the proper value

## Typedef

- `typedef` used for creating new data type names
- A `typedef` declaration does not create a new type in any sense; it merely adds a new name for some existing type

```c
typedef int Length;
Length len, maxlen;      // Length can be used in exactly the same ways that the type int can be

typedef struct tnode *Treeptr;
typedef struct tnode {
  char *word;
  int count;
  Treeptr left;
  Treeptr right;
} Treenode;

Treeptr talloc(void) {
  return (Treeptr) malloc(sizeof(Treenode));
}

// create the type PFI for "pointer to function (of two char * arguments) returning int"
typedef int (*PFI)(char *, char *);
PFI strcmp, numcmp;
```

- There are 2 main reasons for using `typedef`
  1. Parameterize a program against portability problems
    - If `typedef` are used for data types that may be machine-dependent, only the `typedef` need change when the program is moved  (eg. `size_t`, `ptrdiff_t`)
  2. Provide better documentation for a program
    - eg. `Treeptr` may be easier to understand than one declared only as a pointer to a complicated structure

## Unions

- Provide a way to manipulate different kinds of data in a single area of storage, without embedding any machine-dependent information in the program
- The purpose of union - a single variable that can legitimately hold any one of several types:
  ```c
  union u_tag {
    int ival;
    float fval;
    char *sval;
  } u;
  ```
  - The variable u will be large enough to hold the largest of the three types
  - The specific size is implementation-dependent
  - Type retrieved must be the type most recently stored
- A union is a structure in which all members have offset zero from the base
- Syntactically, union is similar as struct
- A union may only be initialized with a value of the type of its first member