#ifndef _PYLONGOBJECT_H
#define _PYLONGOBJECT_H

#include <iostream>

using namespace std;

struct PyLongObject {
    PyLongObject(long long _iValue);

    int sign; // +1 or -1.
    int numDigits;
    bool fitsInLongLong;
    long long iValue;
    unsigned *digitsBase30;

    int getDigitN(int n) const;  // returns -1 on failure
    long long getSmallValue();

    bool operator==(const PyLongObject & other) const;
    PyLongObject operator+(const PyLongObject & other) const;

};

#endif
