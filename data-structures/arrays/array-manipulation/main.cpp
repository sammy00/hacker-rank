#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long> arr(1 + n, 0);
    int a, b, k;

    while (--m >= 0) {
        cin >> a >> b >> k;
        for (int i = a; i <= b; ++i) {
            arr[i] += k;
        }
    }

    cout << *(std::max_element(std::begin(arr), std::end(arr))) << endl;

    return 0;
}