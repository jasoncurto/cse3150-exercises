#ifndef _NODE_H
#define _NODE_H

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
    friend std::ostream& operator<<(std::ostream& os, const Node& node) {
        os << node.data;
        return os;
    }
    Node() : data{0}, next{this}  {}
    Node(int _data) : data{_data}, next{this}  {}
};


#endif