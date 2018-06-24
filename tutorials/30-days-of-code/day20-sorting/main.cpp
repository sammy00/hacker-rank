#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int c(std::move(a));
    a = std::move(b);
    b = std::move(c);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &a : arr) {
        cin >> a;
    }

    int num_swaps{};
    for (int i = 0; i < n; i++) {
        // Track number of elements swapped during a single array traversal
        int numberOfSwaps = 0;

        for (int j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                numberOfSwaps++;
            }
        }

        // If no elements were swapped during a traversal, array is sorted
        if (numberOfSwaps == 0) {
            break;
        }
        num_swaps += numberOfSwaps;
    }

    cout << "Array is sorted in " << num_swaps << " swaps." << endl;
    cout << "First Element: " << arr[0] << endl;
    cout << "Last Element: " << arr.back() << endl;

    return 0;
}