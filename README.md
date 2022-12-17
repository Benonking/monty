# Building a monty bytecode interpreter

## The Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files
### Monty byte code files
Files containing the Monty byte codes usually have the .m extension

### Project files
- monty.h  - contains all the structures and function protypes
- main.c - main function for monty interpreter

### Compilation and Output
- $ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
