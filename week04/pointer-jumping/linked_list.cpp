#include <iostream>

#include "linked_list.h"

using namespace std;


LinkedList::LinkedList() : root{nullptr} {}

void LinkedList::insertInFront(int _data) {
    Node * insertNode = new Node(_data);

    if (root) {
         insertNode->next = root;
    } 
    root = insertNode;
}

LinkedList::~LinkedList() {
    if (!root) return;
    
    Node * current = root;
    while(current && current->next != current) {
        Node * next = current->next;
        delete current;
        current = next;
    }
    if (current && current->next == current) {
        delete current;
    }
}

void LinkedList::traverseList() {
    Node * current = root;

    while(current && current->next != current) {
        cout << "in ~LinkedList " 
            << static_cast<void *>(current) << " next: " 
            << static_cast<void *>(current->next) << endl;
        current = current->next;            
    }
    if (current && current->next == current) {
        cout << "in ~LinkedList " 
             << static_cast<void *>(current) << " next: " 
             << static_cast<void *>(current->next) << endl;
    }

}


ostream & operator<<(ostream & os, const Node & node) {
    os << node.data;
    return os;
}

ostream & operator<<(ostream & os, const LinkedList & linkelist) {
    Node * traversal = linkelist.root;

    while (traversal &&  traversal != traversal->next) {
        os << *traversal 
           << " ";
        traversal = traversal->next;
    }
    if (traversal && traversal == traversal->next ) {
        os << *traversal ;
    }

    return os;
}
