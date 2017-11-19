#include <iostream>

/*
  Delete Node at a given position in a linked list
  Node is defined as
*/
struct Node {
    int data;
    struct Node *next;
};

Node *Delete(Node *head, int position) {
    // Complete this method
    Node *prev = NULL, *ptr = head;
    while (position && ptr) {
        prev = ptr;
        ptr = ptr->next;
        --position;
    }

    if (!prev) {
        head = (ptr ? ptr->next : NULL);
    } else {
        prev->next = ptr->next;
    }
    delete ptr;

    return head;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}