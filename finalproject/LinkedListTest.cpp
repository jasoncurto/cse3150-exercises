#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

TEST_CASE("Circular Linked List testing w/ shared_ptr and weak_ptrs") {
    LinkedList ll;

    ll.SERVER_buildCircularLinkedList();

    cout << "--- Step 2: Server Print Output ---" << endl;
    ll.SERVER_printLinkedList();

    cout << "\n--- Step 3: Client Print Output ---" << endl;
    ll.CLIENT_printLinkedList();

    CHECK(ll.root.use_count() == 3);
    auto* zero_address = ll.root.get();

    ll.node = ll.root;
    for(int i = 0; i < 5; i++) {
        ll.node = ll.node->next;
    }

    cout << "First Node Address: " << zero_address << endl;
    cout << "Tail   Next Address: " << ll.node->next.get() << endl;
    CHECK(ll.node->next.get() == zero_address);

    cout << "\n--- Step 4: Destructor ---" << endl;
    ll.SERVER_deleteCircularLinkedList();

    cout << "\n--- Step 5: Client Print post destruction ---" << endl;
    ll.CLIENT_printLinkedList();

    CHECK(ll.wp.expired() == true);
    
    ll.node.reset();
}