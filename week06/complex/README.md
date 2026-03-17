To compile my program, simply use:

g++ -std=c++23 mainComplexArray.cpp ComplexArray.cpp Complex.cpp
./a.out

A makefile may also be created to use 'make' instead of a long list of cpp files

The programs purpose is to construct dynamically allocated arrays to hold complex numbers. We use Complex.h as a codebase for managing real and imaginary numbers, as well as a ComplexArray.h headerfile which contains constructors, deletions, and other operations.

After running, the program will then prompt the user for the number of complex number pairs to enter (x y).
The program will output the result of the move constructor, as well as the final resulting array after move assignment. It will delete any extra memory from the heap, and clears valgrind as expected. This can be tested by running:

valgrind ./a.out

