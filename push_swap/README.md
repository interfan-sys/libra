*This project has been writen as a part of the 42 core curriculum by agkicina*

# Description
push_swap is a project about sorting a list of integers using a limited set of operations and two stacks.
The goal of this project is to learn the basics of algorithms, data structures, and optimization.

In this project, numbers are stored in stack A and must be sorted in ascending order using stack B and only allowed operations.  
The challenge is not just to sort the numbers, but to do it using the smallest number of moves possible.

# Instructions
Installation & Execution:
1. Compile the program using:
   - make
2. Run the program with integers as arguments:
   - ./push_swap 4 2 3 1
3. The program will output the sequence of operations needed to sort the numbers

Cleaning:
- make clean → removes object files  
- make fclean → removes object files and executable  
- make re → recompiles everything  

# Requirements
- C compiler (cc)
- Make

# Project Design Choices

# Data Structure: Linked List
Linked lists were chosen because they:
- Allow dynamic memory management
- Make stack operations easier (push, rotate, etc.)
- Fit well with the project requirements

# Sorting Strategy
Small sets:
- Simple sorting for 2, 3, and 5 numbers

Large sets:
- Radix sort algorithm used for efficiency and fewer operations

# Radix Sort
*Radix Sort* efficient for large datasets and reduces number of operations      

# Resources
- GeeksforGeeks: https://www.geeksforgeeks.org/
- Stack Overflow: https://stackoverflow.com/
- Other educational chanels on youtube.

# AI Usage
AI was used to:
- Help understand algorithms like radix sort
- Assist with debugging and problem solving.

# Notes
This project focuses on understanding sorting algorithms, optimizing operations, and working with stacks and linked lists.