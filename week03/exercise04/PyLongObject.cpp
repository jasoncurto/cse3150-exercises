#include <iostream>

#include "PyLongObject.h"

PyLongObject::PyLongObject(long long _iValue) {
    iValue = _iValue;
    fitsInLongLong = true;
    numDigits = 0;
    digitsBase30 = NULL;
    if (iValue < 0) {
        sign = -1;
        iValue = -iValue;
    } else {
        sign = 1;
    }
}

PyLongObject::PyLongObject(const PyLongObject & other) {
    this->sign = other.sign;
    this->numDigits = other.numDigits;
    this->fitsInLongLong = other.fitsInLongLong;
    this->iValue = other.iValue;
    if (other.digitsBase30 != NULL) {
        this->digitsBase30 = new unsigned[this->numDigits];
        for (int i = 0; i < this->numDigits; i++) {
            this->digitsBase30[i] = other.digitsBase30[i];
        }
    } else {
        this->digitsBase30 = NULL;
    }
}
PyLongObject::~PyLongObject() {
    delete[] this->digitsBase30;
}

int PyLongObject::getDigitN(int n) const {  // returns -1 on failure
    if (n > numDigits && !fitsInLongLong) {
        return -1;
    } else {
        return digitsBase30[n];
    }
}

long long PyLongObject::getSmallValue() {
    if (fitsInLongLong) {
        return iValue;
    } else {
        return -1;
    }
}

PyLongObject PyLongObject::operator+(const PyLongObject & other) const{
    if(this->fitsInLongLong && other.fitsInLongLong){
        return PyLongObject(this->iValue + other.iValue);
    }
    return(PyLongObject(0));
}

bool PyLongObject::operator==(const PyLongObject & other) const {
    if (this == &other) {
        return true;
    } else {
        if (fitsInLongLong != other.fitsInLongLong) return false;
        if (fitsInLongLong == other.fitsInLongLong && true == fitsInLongLong) {
            if (iValue == other.iValue) {
                return true;
            } else {
                return false;
            }
        }
        if (fitsInLongLong == other.fitsInLongLong && false == fitsInLongLong) {
            if (numDigits != other.numDigits) {
                return false;
            } else {
                for (int i = 0; i < numDigits; i++) {
                    if (getDigitN(i) != other.getDigitN(i)) {
                        return false;
                    }
                }
            }
        }
    }
}

ostream & operator<<(ostream & os, const PyLongObject & pyLongObject) {
    if (pyLongObject.fitsInLongLong) {
        os << pyLongObject.iValue;
    } else {

    }

    return os;
};
