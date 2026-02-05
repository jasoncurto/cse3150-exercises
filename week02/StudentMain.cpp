#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

int main() {

    vector<Student> arr;
    int count;
    cout << "How many students would you like to enter?: " << endl;
    if(!(cin >> count)){ cout << "Invalid input, terminating."; return 1;}
    for(int i = 1; i <= count; i++){
        cout << "Enter data for Student #" << i << ": " << endl;
        Student student = get_student_struct_data();
        arr.push_back(student);
        cin.clear();
        cin.ignore(1000, '\n');
    }
    for(const auto& student : arr){
        cout << student << endl;
    }
    return 0;
}