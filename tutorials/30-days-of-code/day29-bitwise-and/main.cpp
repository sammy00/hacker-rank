#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int num_test;

    cin >> num_test;

    vector<int> vec(1000);
    std::iota(std::begin(vec), std::end(vec), 1);

    size_t n, k;
    while (--num_test >= 0) {
        cin >> n >> k;

        size_t max{0};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (((vec[i] & vec[j]) > max) &&
                    ((vec[i] & vec[j]) < k)) {
                    max = vec[i] & vec[j];

                    if (k == max + 1) { break; }
                }
            }
            if (k == max + 1) { break; }
        }

        cout << max << endl;
    }

    return 0;
}