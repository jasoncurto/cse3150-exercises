#include "LinkedList.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

    void LinkedList::SERVER_buildCircularLinkedList() {
        names = { "zero", "one", "two", "three", "four", "five" };
        numberOfNodes = names.size();
        node = root;
        root = make_shared<Node>(names[0]);
        //wp = root;
        node = root;

        for(int i=1; i < numberOfNodes; i++) {
            node->next = make_shared<Node>(names[i]);
            node->next_weak = node->next;
            //wp = node->next;
            node = node->next;
        }
        node->next = root;
        node->next_weak = root;
        //wp = node->next;
        node = root;
        wp = root;
    }
    void LinkedList::SERVER_deleteCircularLinkedList() {
        for(int i = 0; i < numberOfNodes - 1; i++){
            node = node->next;
        }
        node->next = nullptr;
        root.reset();
        node.reset();
    }
    void LinkedList::SERVER_printLinkedList() {
        for(int i = 0; i < numberOfNodes; i++){
            cout << "[" << names[i] << "] : use_count: " << node.use_count() << " address: " << node << " next (from shared_ptr): " << node->next << "\n";
            node = node->next;
        }
    }
    void LinkedList::CLIENT_printLinkedList() {
        node = wp.lock();
        if(node == nullptr) {
            cout << "[Nothing], linked list has been deleted." << endl;
            return;
        }
        for(int i = 0; i < numberOfNodes; i++){
            cout << "[" << names[i] << "] : use_count: " << node.use_count() << " address: " << node << " next (from weak_ptr): " << node->next_weak.lock() << "\n";
            node = node->next_weak.lock();
        }
    }
/*
int main(){
    LinkedList ll;
    ll.SERVER_buildCircularLinkedList();
    ll.SERVER_printLinkedList();
    cout << "\n";
    ll.CLIENT_printLinkedList();
    cout << "\n";
    ll.SERVER_deleteCircularLinkedList();
    ll.CLIENT_printLinkedList();
}
    */