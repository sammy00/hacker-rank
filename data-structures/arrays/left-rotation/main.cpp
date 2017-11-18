#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> arr(n);
    for (auto &a : arr) {
        cin >> a;
    }

    for (int i = d; i < n; ++i) {
        cout << arr[i] << " ";
    }
    for (int i = 0; i < d; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}