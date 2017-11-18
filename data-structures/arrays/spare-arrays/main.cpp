#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> dict;
    string word;

    while (--n >= 0) {
        cin >> word;
        ++dict[word];
    }

    int num_query;
    cin >> num_query;
    while (--num_query >= 0) {
        cin >> word;
        cout << dict[word] << endl;
    }

    return 0;
}