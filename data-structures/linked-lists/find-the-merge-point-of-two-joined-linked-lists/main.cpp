#include <iostream>
#include <stack>

/*
   Find merge point of two linked lists
   Node is defined as
*/
struct Node {
    int data;
    Node *next;
};

Node *reverse(Node *head) {
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

int FindMergeNode(Node *headA, Node *headB) {
    // Complete this function
    // Do not write the main method.
    auto linkA = reverse(headA);

    auto linkB = headB;
    std::stack<Node *> s;
    while (linkB) {
        s.push(linkB);
        linkB = linkB->next;
    }

    linkA = reverse(linkA);
    Node *prev = NULL; // common node last seen
    while (!s.empty() && (s.top() == linkA)) {
        prev = linkA;
        linkA = linkA->next;
        s.pop();
    }

    return prev->data;
}

int FindMergeNodeV2(Node *headA, Node *headB) {
    auto linkA = headA, linkB = headB;
    while (linkA != linkB) {
        linkA = (linkA->next ? linkA->next : headB);
        linkB = (linkB->next ? linkB->next : headA);
    }

    return linkA->data;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}