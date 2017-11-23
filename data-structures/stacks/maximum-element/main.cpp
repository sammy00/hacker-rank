#include <iostream>
#include <stack>

using namespace std;

class MaxStack {
private:
    stack<int> fullStack, maxStack;
public:
    void push(int x) {
        fullStack.push(x);
        if (maxStack.empty() || maxStack.top() <= x) {
            maxStack.push(x);
        }
    }

    void pop() {
        if (fullStack.empty()) {
            return;
        }

        if (!maxStack.empty() && (fullStack.top() == maxStack.top())) {
            maxStack.pop();
        }
        fullStack.pop();
    }

    int max() {
        return maxStack.empty() ? std::numeric_limits<int>::min() : maxStack.top();
    }
};

int main() {
    int n;
    cin >> n;

    int type, x;
    MaxStack maxStack;
    while (--n >= 0) {
        cin >> type;
        if (1 == type) {
            cin >> x;
            maxStack.push(x);
        } else if (2 == type) {
            maxStack.pop();
        } else {
            cout << maxStack.max() << endl;
        }
    }

    return 0;
}