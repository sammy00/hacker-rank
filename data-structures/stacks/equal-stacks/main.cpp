#include <iostream>
#include <queue>

using namespace std;

int main() {
    const int NUM_STACK = 3;
    int nvec[NUM_STACK];

    for (auto &i : nvec) {
        cin >> i;
    }

    queue<int> qvec[NUM_STACK];
    int hvec[NUM_STACK] = {0};
    int x;

    for (int i = 0; i < NUM_STACK; ++i) {
        while (--nvec[i] >= 0) {
            cin >> x;

            qvec[i].emplace(x);
            hvec[i] += x;
        }
    }

    bool neq = true;
    while (neq) {
        neq = false;
        for (const auto &h : hvec) {
            if (h != hvec[0]) {
                neq = true;
                break;
            }
        }
        if (!neq) { break; }

        int i = 0;
        // find the highest stack
        for (int j = 1; j < NUM_STACK; ++j) {
            if (hvec[j] > hvec[i]) {
                i = j;
            }
        }
        // remove the cylinder
        hvec[i] -= qvec[i].front();
        qvec[i].pop();

        for (const auto &q:qvec) {
            if (q.empty()) {
                for (auto &h:hvec) { h = 0; }
                break;
            }
        }
    }

    cout << hvec[0] << endl;


    return 0;
}