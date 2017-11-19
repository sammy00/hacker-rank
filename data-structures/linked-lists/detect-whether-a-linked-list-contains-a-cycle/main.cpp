#include <iostream>

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
*/
struct Node {
    int data;
    struct Node *next;
};

bool has_cycle(Node *head) {
    // Complete this function
    // Do not write the main method
    Node *ptr1, *ptr2;

    ptr1 = head;
    ptr2 = (head ? head->next : NULL);

    while (ptr1 && ptr2) {
        if (ptr1 == ptr2) {
            return true;
        } else if (!ptr1->next || !ptr2->next) {
            break;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }

    return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}