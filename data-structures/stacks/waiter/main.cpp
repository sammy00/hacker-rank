#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int BUFFER_MAX = 100000;

// Linear primes probing
vector<int> probePrimes(int num_primes) {
    vector<int> primes;

    vector<bool> is_prime(3, false);
    is_prime[2] = true;

    int i = 2;
    while (primes.size() < num_primes) {
        if (is_prime[i]) {
            primes.emplace_back(i);
        }

        for (const auto &p : primes) {
            int composite = i * p;

            if (composite > BUFFER_MAX) { break; }
            if (composite >= is_prime.size()) {
                is_prime.resize(composite + 1, true);
            }

            is_prime[composite] = false;

            if (0 == i % p) { break; }
        }

        ++i;
    }

    return primes;
}

int main() {
    int n, q;

    cin >> n >> q;

    auto primes = probePrimes(q);
    /*
    for (const auto &p : primes) {
        cout << p << " ";
    }
    cout << endl;
    */

    stack<int> prevA;
    int x{};
    while (--n >= 0) {
        cin >> x;
        prevA.emplace(x);
    }

    stack<int> A, B;
    for (int i = 0; i < q; ++i) {
        while (!prevA.empty()) {
            auto x = prevA.top();
            prevA.pop();
            if (0 == x % primes[i]) {
                B.emplace(x);
            } else {
                A.emplace(x);
            }
        }

        while (!B.empty()) {
            cout << B.top() << endl;
            B.pop();
        }
        prevA.swap(A);
    }
    while (!prevA.empty()) {
        cout << prevA.top() << endl;
        prevA.pop();
    }

    return 0;
}