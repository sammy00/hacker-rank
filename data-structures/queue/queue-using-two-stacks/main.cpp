#include <iostream>
#include <stack>

using namespace std;

int main() {
    int num_query{};
    cin >> num_query;

    int type, x;
    stack<int> Q, S;
    while (--num_query >= 0) {
        cin >> type;
        if (1 != type) {
            if (Q.empty()) {
                while (!S.empty()) {
                    Q.emplace(S.top());
                    S.pop();
                }
            }

            if (3 == type) {
                cout << Q.top() << endl;
            } else {
                Q.pop();
            }

            continue;
        }

        cin >> x;
        S.emplace(x);
    }

    return 0;
}