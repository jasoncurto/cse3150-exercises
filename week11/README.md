g++ -std=c++23 testfrac.cpp
./a.out

My program is separated into a couple header files and cpp files

doctest.h - used for testing

bigfrac.h - holds function declarations for multFracs, sumFracs, and fracToString, as well as housing the pair declaration for bigint pairs.

bigint.h - codebase given

bigint_fractions.cpp - the beef of the program which holds the definitions for the above functions.

testfrac.cpp - testing for functionality.

How my files are currently set up requires the user to run the doctest to compile. Otherwise, there is a mismatch with the included header files. This is why doctest extends to bigint_fractions.cpp as this seemed like the best solution to my problem.
