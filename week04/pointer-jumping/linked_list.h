#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>

#include "Node.h"

using namespace std;

class LinkedList {

    friend ostream & operator<<(ostream & os, const LinkedList & linkelist);

    Node * root;

    public:
        LinkedList();
        ~LinkedList();
        void insertInFront(int _data);
        void traverseList();

};


#endif