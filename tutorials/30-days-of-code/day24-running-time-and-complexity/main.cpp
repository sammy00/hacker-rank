#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int num_cases;
    cin >> num_cases;

    int n;
    while (--num_cases >= 0) {
        cin >> n;

        if (n <= 1) {
            cout << "Not prime" << endl;
            continue;
        }

        bool is_prime{true};
        for (auto i = (int) (std::sqrt(n)); i >= 2; --i) {
            if (0 == n % i) {
                is_prime = false;
                break;
            }
        }
        cout << (is_prime ? "Prime" : "Not prime") << endl;
    }

    return 0;
}