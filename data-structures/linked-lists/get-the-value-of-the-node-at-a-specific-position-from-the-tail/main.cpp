#include <iostream>

/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as
*/
struct Node {
    int data;
    struct Node *next;
};

int GetNode(Node *head, int positionFromTail) {
    // This is a "method-only" submission.
    // You only need to complete this method.
    Node *ptr = head;
    while (positionFromTail >= 0) {
        ptr = ptr->next;
        --positionFromTail;
    }
    Node *prev = head;
    while (ptr) {
        prev = prev->next;
        ptr = ptr->next;
    }

    return prev->data;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}