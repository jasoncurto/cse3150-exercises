#include <iostream>

#include "linked_list.h"

using namespace std;


int main() {

        LinkedList linkedList;

        for (int i=0; i < 5; i++) {
            linkedList.insertInFront(i);
        }

        cout << linkedList << endl;
        cout << endl;


        cout << "Basic list traversal with memory addresses" << endl;
        cout << "------------------------------------------" << endl;
        linkedList.traverseList();


    return 0;
}