# The-C-Programming-Language-2nd-Edition

Notes and record for The C Programming Language 2nd Edition by Brian W. Kernighan and Dennis M. Ritchie

- **Detail description & key points are commentted on each section's example program(usually the first one)**
- **Every exercise's problem description also provided as comment in the code**

## Ch1. A Tutorial Introduction

[Hello World](./ch1/hello_world.c)

### Getting Started

[Hello World - First Program](./ch1/hello_world.c)

#### Exercises

[1.2](./ch1/exercise2.c)

### Variable and Arithmetic Expressions

[Temperature Conversion](./ch1/f_to_c.c)

#### Exercises

[1.3](./ch1/exercise3.c), [1.4](./ch1/exercise4.c)

### The For statement

[Temperature Coversion For Loop Version](./ch1/exercise5.c)

#### Exercises

[1.5](./ch1/exercise5.c)

### Symbolic Constants

[Temperature Conversion with Symbolic Constants](./ch1/f_to_c_symbolic_constant.c)

### Character Input and Output

[File Copying](./ch1/file_copying.c)

[Character Counting](./ch1/char_count.c)

[Line Counting](./ch1/line_count.c)

[Word Counting](./ch1/word_count.c)

#### Exercises

[1.6](./ch1/exercise6.c), [1.7](./ch1/exercise7.c), [1.8](./ch1/exercise8.c), [1.9](./ch1/exercise9.c), [1.10](./ch1/exercise10.c), [1.11](./ch1/exercise11.c), [1.12](./ch1/exercise12.c)

### Arrays

[Digits Counting](./ch1/digits_count.c)

#### Exercises

[1.13](./ch1/exercise13.c), [1.14](./ch1/exercise14.c)

### Functions

[Power Function](./ch1/power.c)

#### Exercises

[1.15](./ch1/exercise15.c)

### Arguments - Call by Value

- In C, all function arguments are passed "by value". This means that the called function is given the values of its arguments in temporary variables rather than the original
- When necessary, it is possible to arrange for a function to modify a variable in a calling routine. The caller must provide the **address** of the variable to be set (technically a **pointer** to the variable)
- When the name of an array is used as an argument, the value passed to the function is the location or address of the beginning of the array - there is no copying of array elements
