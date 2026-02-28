#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

using namespace std;


TEST_CASE("basic linkedlist ops to test code base - had to modify a little bit to get it working") {
    LinkedList list;
    CHECK(list.getSize() == 0);

    list.insertAtEnd(1);
    list.insertAtEnd(-1);
    list.insertAtEnd(-1);

    CHECK(list.getSize() == 3);
    CHECK(list.getValueAt(0) == 1);
    CHECK(list.getValueAt(2) == -1);
}

TEST_CASE("copy constructor") {
    LinkedList l;
    l.insertAtEnd(-1);
    l.insertAtEnd(-1);
    l.insertAtEnd(1);

    Node* ogAdd = l.getFirstElement();
    Node* ogAdd2 = ogAdd->next;

    l.copyAllNodesAddresses();
    l.runPointerJumps();

    CHECK(l.getFirstElement() == ogAdd);
    CHECK(l.getAddressFromArray(1) == static_cast<void*>(ogAdd2));
    CHECK(ogAdd->next->data == 1);
    CHECK(ogAdd->data == -1);
}

TEST_CASE("deleting given node") {
    LinkedList l;
    l.insertAtEnd(1);
    l.insertAtEnd(1);
    l.insertAtEnd(-1);

    SUBCASE("delete middle node") {
        l.deleteNodeNumber(1);
        CHECK(l.getSize() == 2);
        CHECK(l.getValueAt(1) == -1);
    }

    SUBCASE("delete root") {
        l.deleteNodeNumber(0);
        CHECK(l.getValueAt(0) == 1);
    }

    SUBCASE("delete tail") {
        l.deleteNodeNumber(2);
        CHECK(l.getSize() == 2);
        CHECK(l.getLastElement()->data == 1);
    }
}

TEST_CASE("prefix sum check") {
    LinkedList pos;
    LinkedList neg;
    SUBCASE("pos") {
        pos.insertAtEnd(1);
        pos.insertAtEnd(1);
        CHECK(pos.check_prefix_sum() == 1);
    }
    
    SUBCASE("neg") {
        neg.insertAtEnd(-1);
        neg.insertAtEnd(-1);
        CHECK(neg.check_prefix_sum() == -1);
    }
}

TEST_CASE("point jump check") {
    LinkedList l;
    l.insertAtEnd(1);
    l.insertAtEnd(1);
    l.insertAtEnd(1);
    l.insertAtEnd(-1);

    l.copyAllNodesAddresses();
    l.runPointerJumps();

    Node* root = l.getFirstElement();
    CHECK(root->next->data == 1); 
    
    Node* secondNode = static_cast<Node*>(l.getAddressFromArray(1));
    CHECK(secondNode->next->data == -1);
}