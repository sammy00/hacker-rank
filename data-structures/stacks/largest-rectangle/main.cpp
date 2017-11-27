#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> hvec;

    cin >> n;
    hvec.reserve(n);
    for (int i = 0; i < hvec.size(); ++i) {
        cin >> hvec[i];
    }

    int left = 0, right = n - 1;
    int area_max = n * std::min(hvec[0], hvec.back());
    while (left < right) {
        if (hvec[left] < hvec[right]) {
            while ((left<right) && ())
        }
    }

    return 0;
}