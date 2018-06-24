#include <algorithm>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

struct people {
    string name;
    string email;


    people(string name, string email) : name{name}, email{email} {}
};

int main() {
    int n;
    cin >> n;

    vector<people> contacts;
    string name, email;
    while (--n >= 0) {
        cin >> name >> email;

        /*
        if (hasSuffix(email, "@gmail.com")) {
            contacts.emplace_back(name, email);
        }
         */
        contacts.emplace_back(name, email);
    }

    auto rmItr = std::remove_if(std::begin(contacts), std::end(contacts), [](const auto &c) {
        const regex re{"[a-z]+@gmail\\.com$"};
        return !std::regex_match(c.email, re);
    });

    contacts.erase(rmItr, std::end(contacts));
    std::sort(std::begin(contacts), std::end(contacts),
              [](const auto &c1, const auto &c2) { return c1.name < c2.name; });

    for (const auto &c : contacts) {
        cout << c.name << endl;
    }

    return 0;
}