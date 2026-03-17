#include "ComplexArray.h"
#include <iostream>
using namespace std;

ComplexArray::ComplexArray(size_t n) : size{n} {
    data = new Complex[size]; 
}

ComplexArray::~ComplexArray() {
    delete[] data;
}

ComplexArray::ComplexArray(ComplexArray&& other) : data{other.data}, size{other.size} {
    other.data = nullptr;
    other.size = 0;
}

ComplexArray& ComplexArray::operator=(ComplexArray&& other){
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

void ComplexArray::modElementAtI(size_t index, const Complex& c) {
    if (index < size) {
        data[index] = c;
    }
}

void ComplexArray::printArray() const {
    if (!data) {
        cout << "Array is empty boss" << endl;
        return;
    }
    for (size_t i = 0; i < size; i++) {
        cout << "  " << data[i] << endl;
    }
}