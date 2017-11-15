#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    string S;
    while (--T >= 0) {
        cin >> S;

        for (int i = 0; i < S.size(); i += 2) {
            cout << S[i];
        }
        cout << " ";
        for (int i = 1; i < S.size(); i += 2) {
            cout << S[i];
        }
        cout << endl;
    }

    return 0;
}