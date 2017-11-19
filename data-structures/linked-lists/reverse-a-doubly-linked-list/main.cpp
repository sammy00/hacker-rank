#include <iostream>

/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
*/
struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node *Reverse(Node *head) {
    // Complete this function
    // Do not write the main method.
    Node *prev = NULL;
    while(head) {
        auto cache = head->next;

        head->next = prev;
        head->prev = cache;
        prev = head;

        head = cache;
    }

    return prev;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}