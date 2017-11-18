#include <iostream>

using namespace std;
/*
  Insert Node at the end of a linked list
  head pointer input could be NULL as well for empty list
  Node is defined as
  */
struct Node {
    int data;
    struct Node *next;
};

Node *Insert(Node *head, int data) {
// Complete this method

    if (!head) {
        head = new Node;
        head->data = data;
        head->next = NULL;
    } else {
        Node *prev = head;
        while (prev->next) {
           prev = prev->next;
        }
        prev->next = new Node;
        prev->next->data = data;
        prev->next->next = NULL;
    }

    return head;
}

int main() {

    return 0;
}