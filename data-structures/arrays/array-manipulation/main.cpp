#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long> arr(2 + n, 0);
    int a, b, k;

    while (--m >= 0) {
        cin >> a >> b >> k;
        arr[a] += k;
        arr[b + 1] -= k;
    }

    long val{}, max{};
    for (const auto &x : arr) {
        val += x;
        max = (max >= val ? max : val);
    }

    cout << max << endl;

    return 0;
}