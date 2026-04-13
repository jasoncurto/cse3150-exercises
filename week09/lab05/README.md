Jason Curto
Lab05 - Cos-distance

The program is set up with a header file to declare functions & structs used: vectorMag, dotProduct, getAlpha, findSortedPairs. The functions calculate the magnitude of a given vector, calculate the dot product of given vectors, calculates the distance, and constructs the pairs in order, respectively. These functions are defined in the cosCloseness.cpp file.

There is also a test_cosCloseness.cpp and vectors.txt file. The test file is used to load the vectors file and compute the vector distances. The vectors text file can be edited to include any K^2+ dimension vectors, but currently houses the 5D vectors given on the assignment sheet for testing. The program is currently set up to use the doctest as the primary motor for testing the vectors.txt file, but it is equally possible to create a main function under cosCloseness.cpp to load the file and pass the data; I felt that the current approach was more organized and feasible.

The program may be compiled with:

g++ -std=c++23 test_cosCloseness.cpp cosCloseness.cpp
./a.out