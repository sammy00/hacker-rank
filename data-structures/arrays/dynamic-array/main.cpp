#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> seqs(N, vector<int>{});
    int last_answer{};
    int query_enum, x, y;
    while (--Q >= 0) {
        cin >> query_enum >> x >> y;

        auto i = (x ^ last_answer) % N;
        if (1 == query_enum) {
            seqs[i].emplace_back(y);
        } else {
            last_answer = seqs[i][y % seqs[i].size()];
            cout << last_answer << endl;
        }
    }

    return 0;
}