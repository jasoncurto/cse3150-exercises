#include <iostream>
#include "ComplexArray.h"
#include "Complex.h"
using namespace std;

int main() {
    size_t count;

    cout << "How many complex numbs wouLd you like to enter? ";
    if (!(cin >> count)) {
        return 1;
    }

    ComplexArray x(count);

    for (size_t i = 0; i < count; i++) {
        double real; 
        double imaginary;
        cout << "Enter real and imaginary for index " << i << ": ";
        cin >> real >> imaginary;
        x.modElementAtI(i, Complex(real, imaginary));
    }
    cout << "\nMove Constructor\n";
    ComplexArray movedX = move(x);
    cout << "\nResult in moved:\n";
    movedX.printArray();

    cout << "\nMove Assignment" << endl;
    ComplexArray moveX(0);
    moveX = move(movedX);

    cout << "\nFinal Result:\n";
    moveX.printArray();

    return 0;
}