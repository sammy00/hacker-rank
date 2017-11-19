#include <iostream>

using namespace std;
/*
  Insert Node at a given position in a linked list
  head can be NULL
  First element in the linked list is at position 0
  Node is defined as
*/
struct Node {
    int data;
    struct Node *next;
};

Node *InsertNth(Node *head, int data, int position) {
    // Complete this method only
    // Do not write main function.
    Node *prev = NULL, *ptr = head;
    while (position && ptr) {
        prev = ptr;
        ptr = ptr->next;
        --position;
    }

    if (!prev) {
        // prev is the node before head
        prev = new Node;
        prev->data = data;
        head = prev;
    } else {
        ptr = new Node;
        ptr->data = data;
        ptr->next = prev->next;
    }

    prev->next = ptr;

    return head;
}

int main() {
    // 3
    // 35
    // 354
    // 3542
    // 310542

    return 0;
}