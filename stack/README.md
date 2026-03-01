Here is a detailed README.md file for the `.\stack` folder:

**Folder Overview**
====================

This folder contains several C programming language files that implement various stack-based data structures and algorithms. The files are:

* `balancedparentheses.c`: Checks if a given string of parentheses is balanced using a stack-based approach.
* `infix_to_prefix.c`: Converts an infix expression to a prefix expression using a stack-based approach.
* `postfix.c`: Evaluates a postfix expression using a stack-based approach.
* `postfix_to_infix.c`: Converts a postfix expression to an infix expression using a stack-based approach.
* `stack.c`: Implements basic push, pop, and display operations on a stack data structure.

**File-by-File Explanation**
==========================

### balancedparentheses.c

This file checks if a given string of parentheses is balanced by pushing opening parentheses onto a stack and popping them when a matching closing parenthesis is encountered. If a closing parenthesis is encountered when the stack is empty, or if the stack is not empty at the end of the string, the function returns `false`, indicating that the parentheses are not balanced.

### infix_to_prefix.c

This file converts an infix expression to a prefix expression by iterating through the input string and using a stack to store operators. When an operator is encountered, it is pushed onto the stack if it has a lower or equal precedence than the top element on the stack. When a non-operator is encountered, it is appended to the output string. When the end of the input string is reached, the elements remaining on the stack are popped and appended to the output string in reverse order.

### postfix.c

This file evaluates a postfix expression by iterating through the input string and using a stack to store operands. When an operator is encountered, two operands are popped from the stack, the operation is performed, and the result is pushed onto the stack. When the end of the input string is reached, the final result is printed.

### postfix_to_infix.c

This file converts a postfix expression to an infix expression by iterating through the input string and using a stack to store operators. When an operand is encountered, it is appended to the output string. When an operator is encountered, the operands from the stack are popped, the operator is appended to the output string, and the result is pushed onto the stack. When the end of the input string is reached, the final result is printed.

### stack.c

This file implements basic push, pop, and display operations on a stack data structure using a dynamic array. The `push` function adds an element to the top of the stack, the `pop` function removes an element from the top of the stack, and the `display` function prints all elements in the stack.

**Functions/Classes explained**
=============================

* `checkBalanced`: Checks if a given string of parentheses is balanced using a stack-based approach.
* `precedence`: Returns the precedence of a given operator.
* `isoperator`: Checks if a given character is an operator.
* `reverse`: Reverses a given string.
* `push`, `pop`, `display`: Basic operations on a stack data structure.

**Dependencies used**
=====================

* `stdio.h`: Standard input/output library.
* `stdlib.h`: Standard library for memory management.
* `string.h`: Standard library for string manipulation.

**Compilation and Execution**
===========================

To compile and run the files, navigate to the `.\stack` folder in your terminal and run the following commands:

* `gcc balancedparentheses.c -o balancedparentheses.exe && ./balancedparentheses.exe`
* `gcc infix_to_prefix.c -o infix_to_prefix.exe && ./infix_to_prefix.exe`
* `gcc postfix.c -o postfix.exe && ./postfix.exe`
* `gcc postfix_to_infix.c -o postfix_to_infix.exe && ./postfix_to_infix.exe`
* `gcc stack.c -o stack.exe && ./stack.exe`