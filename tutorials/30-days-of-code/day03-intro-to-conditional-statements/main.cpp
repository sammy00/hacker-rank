#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    bool wired = (N & 1) || ((N >= 6) && (N <= 20));
    cout << (wired ? "" : "Not ") << "Weird" << endl;

    return 0;
}