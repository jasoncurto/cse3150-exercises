Program layout:

BalancedParensMain.cpp -- prompts user, passed values to func.h, computes the count and proportional lists.

tests.cpp -- houses the doctests to check functionality

func.h -- home of the functions to initialize array, fisher-yates, randomizer, and prefix sum

doctest.h -- used for doctest obviously :)

How to build:

g++ BalancedParensMain.cpp
./a.out

Here is where you can input an integer 'n' to determine array size, and also input an integer 'size' for how many trials to be ran. Program will terminate with an inappropriate value input.

Program will then initialize an array of size n*2 with equal values 1, -1.

Fisher-yates will then scramble this initialized array.

If a negative prefix sum is detected, the list will get tossed. Otherwise, the count goes up per each successful list. This will continue up until 'size' -- the amt of trials

The program will then output the number of positive prefix sum lists, as well as the calculated proportion.

g++ tests.cpp
./a.out

This will run the doctest.h testcases.