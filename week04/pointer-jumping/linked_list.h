#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>

#include "Node.h"
#include <vector>

using namespace std;

class LinkedList{

    friend ostream & operator<<(ostream & os, const LinkedList & linkedList);
    Node * root;
    vector<void *> nodeAddresses; 

    public:
        LinkedList();
        LinkedList(const LinkedList & fromLL);
        void * getAddressFromArray(int i);
        void printAllNodeAddresses();
        void printTableNodesNextValue();
        void copyAllNodesAddresses();
        void pointerJump(Node * head);
        void runPointerJumps();
        void insertAtEnd(int val);
        Node * getFirstElement();
        Node * getLastElement();
        int getSize();
        int getValueAt(int position);
        void deleteNodeNumber(int nodeNumber);
        ~LinkedList();
        int check_prefix_sum();
        void traverseList();
        void insertInFront(int val);
};

#endif