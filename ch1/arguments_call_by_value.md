
- In C, all function arguments are passed **"by value"**. This means that the called function is given the values of its arguments in temporary variables rather than the original
- When necessary, it is possible to arrange for a function to modify a variable in a calling routine. The caller must provide the **address** of the variable to be set (technically a **pointer** to the variable)
- When the name of an array is used as an argument, the value passed to the function is the location or address of the beginning of the array - there is no copying of array elements