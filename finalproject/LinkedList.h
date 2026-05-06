#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <memory>
#include <iostream>
#include <vector>
using namespace std;

struct Node {

    string name;
    Node(string name) : name{name} {}
    shared_ptr<Node> next;
    weak_ptr<Node> next_weak;
    
    ~Node() { cout << "Node [" << name << "] destructor" << endl; }
};

class LinkedList {
    public:
        shared_ptr<Node> root;
        shared_ptr<Node> node;
        weak_ptr<Node> wp;
        vector<string> names;
        int numberOfNodes = names.size();

        void SERVER_buildCircularLinkedList();
        void SERVER_deleteCircularLinkedList();
        void SERVER_printLinkedList();
        void CLIENT_printLinkedList();
};

#endif