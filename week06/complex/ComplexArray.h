#ifndef COMPLEX_ARRAY_H
#define COMPLEX_ARRAY_H

#include "Complex.h"

class ComplexArray {

    Complex* data;
    size_t size;

public:

    ComplexArray(size_t n);
    ~ComplexArray();


    ComplexArray(ComplexArray&& other);
    ComplexArray& operator=(ComplexArray&& other);
    void modElementAtI(size_t index, const Complex& c);
    void printArray() const;
    size_t getSize() const { return size; }
};

#endif