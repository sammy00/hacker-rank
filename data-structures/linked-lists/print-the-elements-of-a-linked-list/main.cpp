#include <iostream>

using namespace std;

/*
  Print elements of a linked list on console
  head pointer input could be NULL as well for empty list
  Node is defined as
*/
struct Node {
    int data;
    struct Node *next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

void Print(Node *head) {
    // This is a "method-only" submission.
    // You only need to complete this method.
    while(head) {
        cout << head->data<<endl;
        head=head->next;
    }
    cout << endl;
}

int main() {
    Node nodes[] = {
            Node(1),
            Node(2),
            Node(3),
    };
    nodes[0].next = nodes+1;
    nodes[1].next = nodes+2;

    Print(NULL);
    Print(nodes);

    return 0;
}