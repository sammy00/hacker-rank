#include <iostream>

/*
  Merge two sorted lists A and B as one linked list
  Node is defined as
*/
struct Node {
    int data;
    struct Node *next;
};

Node *MergeLists(Node *headA, Node *headB) {
    // This is a "method-only" submission.
    // You only need to complete this method
    Node *head_new = new Node;
    head_new->next = NULL;
    auto prev = head_new;

    while (headA && headB) {
        if (headA->data < headB->data) {
            prev->next = headA;
            headA = headA->next;
        } else {
            prev->next = headB;
            headB = headB->next;
        }
        prev = prev->next;
    }
    if (headA) {
        prev->next = headA;
    }
    if (headB) {
        prev->next = headB;
    }

    prev = head_new;
    head_new = head_new->next;
    delete prev;    // don't miss memory release

    return head_new->next;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}