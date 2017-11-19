#include <iostream>

/*
    Insert Node in a doubly sorted linked list
    After each insertion, the list should be sorted
   Node is defined as
*/
struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node *SortedInsert(Node *head, int data) {
    // Complete this function
    // Do not write the main method.
    Node *ptr = head, *prev = NULL;
    // find the 1st node larger than/equal to data
    while (ptr && (ptr->data < data)) {
        prev = ptr;
        ptr = ptr->next;
    }

    auto node_new = new Node;
    node_new->data = data;
    node_new->prev = prev;
    node_new->next = ptr;

    if (prev) {
        prev->next = node_new;
    } else {
        head = node_new;
    }
    if (ptr) {
        ptr->prev = node_new;
    }

    return head;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}