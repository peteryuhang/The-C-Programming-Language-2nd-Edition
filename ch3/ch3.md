- **Statement, if-else**
  - In C, the semicolon is a **statement terminator**
  - When there is a nested if sequence, the else will associate with the **closest** previous if
- **Switch**
  - After the code for one case is done, execution **falls through to the next** unless you take explicit action to escape (**break** and **return** are the most common way to leave a switch)
- **Comma operator**
  - The comma operator often been used on for loop, and been evaluated from left to right
  - The commas that separate function arguments, variables in declarations, etc, are not comma operators, and **do not guarantee left to right evaluation**
  - A comma expression might also be appropriate for the exchange of elements, eg.
    `c = s[i], s[i] = s[j], s[j] = c;`

