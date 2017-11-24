#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Record {
    char op;
    int delta;

    Record(char op, int delta) : op(op), delta(delta) {}
};

int main() {
    int num_op{};
    cin >> num_op;

    vector<char> str_stack;
    stack<Record> op_stack;
    stack<char> trash;

    int op, k;
    string str2add;
    while (--num_op >= 0) {
        cin >> op;
        if (1 == op) {
            cin >> str2add;
            for (const auto &c:str2add) {
                str_stack.push_back(c);
            }
            op_stack.emplace('1', str2add.size());
        } else if (2 == op) {
            cin >> k;
            op_stack.emplace('2', k);
            while (--k >= 0) {
                auto c = str_stack.back();
                str_stack.pop_back();
                trash.push(c);
            }
        } else if (3 == op) {
            cin >> k;
            cout << str_stack[k - 1] << endl;
        } else {
            auto delta = op_stack.top().delta;
            if ('1' == op_stack.top().op) {
                while (--delta >= 0) {
                    str_stack.pop_back();
                }
            } else {
                while (--delta >= 0) {
                    auto c = trash.top();
                    trash.pop();
                    str_stack.push_back(c);
                }
            }
            op_stack.pop();
        }
    }

    return 0;
}