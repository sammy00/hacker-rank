#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int num_bit{};
    while (true) {
        if (!n) { break; }

        int num_bit_tmp{};
        while (n & 1) {
            ++num_bit_tmp;
            n >>= 1;
        }

        if (num_bit < num_bit_tmp) {
            num_bit = num_bit_tmp;
        }

        // shift out the rightmost zero
        n >>= 1;
    }

    cout << num_bit << endl;

    return 0;
}