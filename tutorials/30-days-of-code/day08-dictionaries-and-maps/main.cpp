#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> address_book;
    int n;
    cin >> n;

    string name;
    int tel;
    while (--n >= 0) {
        cin >> name >> tel;
        address_book[name] = tel;
    }

    while (cin >> name) {
        if (std::end(address_book) != address_book.find(name)) {
            cout <<name<<"="<< address_book[name] << endl;
        } else {
            cout << "Not found" << endl;
        }
    }
    return 0;
}