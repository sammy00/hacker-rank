#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    string bracket_str;

    while (--n >= 0) {
        cin >> bracket_str;

        stack<char> bracket_stack;
        bool yes = true;
        for (const auto &c : bracket_str) {
            if (('{' == c) || ('(' == c) || ('[' == c)) {
                bracket_stack.emplace(c);
                continue;
            }

            if (bracket_stack.empty()) {
                yes = false;
                break;
            }

            if (('}' == c) && ('{' != bracket_stack.top())) {
                yes = false;
                break;
            }
            if ((')' == c) && ('(' != bracket_stack.top())) {
                yes = false;
                break;
            }
            if ((']' == c) && ('[' != bracket_stack.top())) {
                yes = false;
                break;
            }

            bracket_stack.pop();
        }

        yes = yes && bracket_stack.empty();
        cout << (yes ? "YES" : "NO") << endl;
    }

    return 0;
}