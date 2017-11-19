#include <iostream>

/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as
  */
struct Node {
    int data;
    struct Node *next;
};

Node *RemoveDuplicates(Node *head) {
    // This is a "method-only" submission.
    // You only need to complete this method.
    auto ptr = head;
    while (ptr) {
        auto next = ptr->next;
        while (next && next->data == ptr->data) {
            ptr->next = next->next;
            delete next;
            next = ptr->next;
        }
        ptr = ptr->next;
    }

    return head;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}