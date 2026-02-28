#include <iostream>
#include "linked_list.h"
using namespace std;

int main() {

    LinkedList linkedList;
    int numNodes;

    cout << "### Linked List Maker :) ###" << endl;
    cout << "How many nodes would you like to create? " << endl;
    
    if (!(cin >> numNodes) || numNodes <= 0) {
        cout << "Invalid input, exiting." << endl;
        return 0;
    }

    for (int i = 0; i < numNodes; ++i) {
        int temp;
        cout << "Enter value for node " << i << " (1 or -1): ";
        cin >> temp;

        if (temp != 1 && temp != -1) {
            cout << "Only 1 or -1 allowed, exiting" << endl;
            return 0; 
        }
        linkedList.insertAtEnd(temp);
    }

    cout << "\nLink success! Current size: " << linkedList.getSize() << endl;

    if (linkedList.getSize() > 0) {
        int index;
        cout << "\nEnter an index to delete (0 to " << linkedList.getSize() - 1 << "): ";
        cin >> index;
        
        if (index >= 0 && index < linkedList.getSize()) {
            linkedList.deleteNodeNumber(index);
            cout << "Given node at index " << index << " deleted. New size: " << linkedList.getSize() << endl;
        } else {
            cout << "Invalid index, skipping this process." << endl;
        }
    }

    int result = linkedList.check_prefix_sum();
    cout << "\nPrefix Sum Result: " << result;
    if (result == 1) cout << " (Positive Prefix Sum)" << endl;
    else cout << " (Negative Prefix Sum)" << endl;

    return 0;
}