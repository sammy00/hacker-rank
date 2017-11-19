#include <iostream>

/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element
  Node is defined as
*/
struct Node {
    int data;
    struct Node *next;
};

Node *Reverse(Node *head) {
    // Complete this method
    Node *prev = NULL, *ptr = head;
    while (ptr) {
        auto cache = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = cache;
    }

    return prev;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}