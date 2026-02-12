#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

int main() {

    Student * head = NULL;
    Student * tail = NULL;
    int count;

    cout << "How many students would you like to enter?: " << endl;
    if(!(cin >> count)){ cout << "Invalid input, terminating."; return 1;}
    for(int i = 1; i <= count; i++){
        cout << "Enter data for Student #" << i << ": " << endl;

        Student * new_node = get_student_node_data();
        if (head == NULL){
            head = new_node;
            tail = new_node;
        }
        else{
            tail->next = new_node;
            tail = new_node;
        }
    }
    Student * tmp = head;
    while(tmp != NULL){
        cout << *tmp << endl;
        tmp = tmp->next;
    }
    tmp = head;
    while(tmp != NULL){
        Student * next = tmp->next;
        delete tmp;
        tmp = next;
    }
    return 0;
}