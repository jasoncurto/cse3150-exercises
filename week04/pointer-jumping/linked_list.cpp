#include <iostream>

#include "linked_list.h"
#include "Node.h"
using namespace std;


LinkedList::LinkedList() : root{nullptr} {}
LinkedList::LinkedList(const LinkedList & fromLL) {
    if (nullptr == fromLL.root){
        root=nullptr;
        return;
    }
    root = new Node(fromLL.root->data);
    Node * currentOld = fromLL.root;
    Node * newList = root;
    while (currentOld->next != currentOld) {
        cout << "HERE: " << currentOld->data << endl;
        newList->next = new Node(currentOld->data);
        currentOld = currentOld->next;
        newList = newList->next;
    }
    newList->data = currentOld->data;
    newList->next = newList;
}
void * LinkedList::getAddressFromArray(int i){
        return static_cast<void *>(nodeAddresses[i]);
}
void LinkedList::insertInFront(int _data) {
    Node * insertNode = new Node(_data);

    if (root) {
         insertNode->next = root;
    } 
    root = insertNode;
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

void LinkedList::printAllNodeAddresses() {
    for (auto address : nodeAddresses) {
        cout << static_cast<void *>(address) << endl;
    }
    cout << endl;
}

void LinkedList::printTableNodesNextValue(){
    cout << " Node address     next-ptr         data" << endl;
    for(auto address: nodeAddresses) {
        cout << static_cast<Node *>(address) << "   " 
                << static_cast<Node *>(address)->next << "     " 
                << static_cast<Node *>(address)->data << endl;
    }
}
void LinkedList::copyAllNodesAddresses() {
    int size = getSize();
    if( size > 0){
        int i = 0;
        Node * current = root;
        while(current != current->next) {
            nodeAddresses.push_back(static_cast<void *>(current));
            current = current->next;
        }
        nodeAddresses.push_back(static_cast<void *>(current));
    }
}

void LinkedList::pointerJump(Node * head){
    if(head && head->next && head != head->next) {
        head->next = head->next->next;
    }
}

void LinkedList::runPointerJumps() {
    for(auto address: nodeAddresses) {
        pointerJump(static_cast<Node *>(address));
    }
}

void LinkedList::insertAtEnd(int val){
    Node * newNode = new Node(val);
    if (!root) {
        root = newNode;
        return;
    }
    Node * current = root;
    while(current->next != current) {
        current = current->next;
    }
    current->next = newNode;
}

Node * LinkedList::getFirstElement() {
    return root;
}

Node * LinkedList::getLastElement() {
    Node * current = root;
    while(current->next != current) {
        current = current->next;
    }
    return current;
}

int LinkedList::getSize() {
    if (!root) return 0;
    int size = 0;
    Node * current = root;
    if(current && current == current->next) {
        size = 1;
    } else {
        while(current && current->next != current) {
            size++;
            current = current->next;
        }
        size++;
    }
    return size;
}

int LinkedList::getValueAt(int position){
    int value = -1;
    if(!root) return value;
    if(position == 0) return root->data;
    int count = 0;
    Node * current = root;
    while(current != current->next && count <= position) {
        count++;
        value = current->data;
        current = current->next;
    }
    if(count == position) {
        value = current->data;
    }
    return value;
}

void LinkedList::deleteNodeNumber(int nodeNumber){ //i had to change some things from your code base. i understand if you have to remove points, but it kept failing so i had to rewrite parts; maybe i messed up somewhere else
    if(!root) return;
    if(nodeNumber == 0) {
        Node * temp = root;
        if (root->next == root) {
            root = nullptr;
        } else {
            root = root->next;
        }
        delete temp;
        return;
    }
    int count = 1;
    Node * lag = root;
    Node * current = root->next;
    while(current != current->next && count != nodeNumber) {
        count++;
        current = current->next;
        lag = lag->next;
    }
    if(count == nodeNumber) {
        if(current->next == current) {
            lag->next = lag;
        } else {
            lag->next = current->next;
        }
        delete current;
    }
}

int LinkedList::check_prefix_sum() {
    if (!root) return 0;

    int runningSum = 0;
    Node* current = root;
    int direction = root->data; 

    while (true) {
        runningSum += current->data;
        if (runningSum * direction < 0) {
            return 0;
        }
        if (current->next == current) break;
        current = current->next;
    }
    return direction;
}

LinkedList::~LinkedList(){
    Node * current = root;
    if(nullptr != root){
        while(current != current->next) {
            Node * next = current->next;
            delete current;
            current = next;
        }
        delete current;
    }
    root = nullptr;
}

ostream & operator<<(ostream & os, const LinkedList & linkedList){
    Node * current = linkedList.root;
    if(nullptr == linkedList.root) {
        return os;
    }else{
        while(current != current->next) {
            os << *current << " ";
            current = current->next;
        }
        os << *current;
    }
    return os;
}