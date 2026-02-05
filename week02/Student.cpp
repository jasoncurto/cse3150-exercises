#include <iostream>

#include "Student.h"

Student get_student_struct_data() {

    Student student;

    string name;

    cout << "Enter name: " << endl;
    cin >> name;
    student.setName(name);

    cout << "Enter midterm: " << endl;
    cin >> student.midterm;

    cout << "Enter final: " << endl;
    cin >> student.final ;

    int countGrades;
    int score;
    cout << "How many homework grades would you like to enter for this student? " << endl;
    if(!(cin >> countGrades)){ 
        cout << "Invalid input, terminating."; 
        countGrades = 0;
        cin.clear();
        cin.ignore(9999, '\n');
    }
    else{
        for(int i = 1; i <= countGrades; i++){
            cout << "Input homework score #" << i << ": " << endl;
            if(cin >> score) {
                student.hw_grades.push_back(score);
            }
            else{
                cout << "Invalid input. Try again." << endl;
                cin.clear();
                cin.ignore(9999, '\n');
                i--;
            }
        }
    }

    return student;
}

ostream & operator<<(ostream & os, const Student & student) {
    os << student.getName()
        << " Midterm: "
        << student.midterm
        << " Final: "
        << student.final
        << " homework scores:";
        for (auto score : student.hw_grades) {
            os  << score
                << " ";
        }

    return os;
}