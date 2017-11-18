#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int calcHourGlassSum(const vector<vector<int>> &arr, const int y, const int x) {
    int sum{};
    // upper row
    for (int i = x + 2; i >= x; --i) {
        sum += arr[y][i];
    }
    // middle row
    sum += arr[y + 1][x + 1];
    // bottom row
    for (int i = x + 2; i >= x; --i) {
        sum += arr[y + 2][i];
    }

    return sum;
}

int main() {
    vector<vector<int> > arr(6, vector<int>(6));
    for (int arr_i = 0; arr_i < 6; arr_i++) {
        for (int arr_j = 0; arr_j < 6; arr_j++) {
            cin >> arr[arr_i][arr_j];
        }
    }


    int max_sum{std::numeric_limits<int>::min()};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            auto tmp_sum = calcHourGlassSum(arr, i, j);
            if (tmp_sum > max_sum) {
                max_sum = tmp_sum;
            }
        }
    }

    cout << max_sum << endl;

    return 0;
}