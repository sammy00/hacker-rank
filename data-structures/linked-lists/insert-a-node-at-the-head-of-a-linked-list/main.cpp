#include <iostream>

/*
  Insert Node at the begining of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as
  */
struct Node {
    int data;
    struct Node *next;
};

//return back the pointer to the head of the linked list in the below method.
Node *Insert(Node *head, int data) {
// Complete this method
    Node *head_new = new Node;
    head_new->data = data;
    head_new->next = head;

    return head_new;
}

int main() {
    auto head = Insert(NULL, 1);
    delete head;
    return 0;
}