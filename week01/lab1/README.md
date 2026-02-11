Name: Jason Curto
Lab: Lab Week 01 - Prefix Sum

Program instructions:

TThe lab1.cpp file is going to prompt the user into whether they want to do the non-pos or non-neg prefix sum by asking for an integer to indicate which function will be used. it will then ask for inputs of 1, -1 until: the input is invalid, the prefix sum evaluates false, or until the user stops the program. The prefix sum is valid as long as the program continues asking for inputs.

testlab1.cpp is the doctest for the prefix sum. I checked all edge cases: leading 1, leading -1, leading 0, numbers other than -1 and 1, etc. the only thing I didn't change for testing sake is making the sum and input values with larger spaces of memory (using a long long or different data type). It just felt unnecessary, but if that is how you wanted it, it was a conscious choice otherwise.

I separated the prefix_sum.h into its own header file to go along with your mindset on doctests: that the program shouldn't even know it's being tested. I'm sure there is a more efficient way to do the header file than I did it, but time is unfortunately low so it'll work as a prototype.