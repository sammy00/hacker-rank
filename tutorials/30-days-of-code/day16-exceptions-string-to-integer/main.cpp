#include <iostream>

using namespace std;

int main() {
    string S;
    cin >> S;

    try {
        int num = std::stoi(S);
        cout << num << endl;
    } catch (const invalid_argument &err) {
        cout << "Bad String" << endl;
    }

    return 0;
}