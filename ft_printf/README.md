# ft_printf
*This project has been created as part of the 42 curriculum by <agkicina>*
---
## Descripiton
    The *printf* project it is about rewriting c standard library function printf, it is not just about rewriting, the goal is also to deepen our understanding of c programming. In this project we learn also about formating and stdarg.h variadic functions va_start, va_arg, va_end.

## Instructions
   
    The project is compiled using the make command. The make command reads the Makefile the commpiler with the required flags compiles .c files to object files .o the object files are archived in the static library which is the name of the program libftprintf.a.
    To execute must be link to another program. For example with main.c:
    cc main.c libftprintf.a.
## Resources
    
    The following resources were used to understand and implement the project:
    man 3 printf - official documentation of the behavior and formatting rules if printf
    GNU C Library Documentation - reference for variadic functions
    42 cursus matirials
    subject PDF - project requirements and conctraints.
    Online articles and tutorials explaning Variadic functions.

    AI Usage
    AI was used as a learning and explanation tool specifically:
    AI was used to explain how recursion works when implementing the hexadecimal printing function (ft_printhex) in order to better understand how numbers are printed digit by digit.

## Explenation of the project
   
    In this project the goal is to rewrite a verison of printf function. The program reads the format string one character at a time and decides what to do depending on what it finds in the next step.
## Algothirem Used
   
    The algorithm works in a simiple way the format string is read from left to right if the character is not % it is printed directly, if % is found the character is checked to know which type should be printed, then correct function is  called using variadic arguments (va_list).
