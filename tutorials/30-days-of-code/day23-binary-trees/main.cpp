#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

class Solution {
public:
    Node *insert(Node *root, int data) {
        if (root == NULL) {
            return new Node(data);
        } else {
            Node *cur;
            if (data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }

    void levelOrder(Node *root) {
        //Write your code here
        if (!root) {
            return;
        }

        queue<Node *> tree;
        tree.push(root);
        while (!tree.empty()) {
            auto node = tree.front();
            tree.pop();

            cout << node->data << " ";

            if (node->left) {
                tree.push(node->left);
            }
            if (node->right) {
                tree.push(node->right);
            }
        }
        cout << endl;
    }
};//End of Solution

int main() {
    Solution myTree;
    Node *root = NULL;
    int T, data;
    cin >> T;
    while (T-- > 0) {
        cin >> data;
        root = myTree.insert(root, data);
    }
    myTree.levelOrder(root);
    return 0;
}
