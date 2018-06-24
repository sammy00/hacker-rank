#include <iostream>

using namespace std;

int main() {
    int day[2], month[2], year[2];

    cin >> day[0] >> month[0] >> year[0];
    cin >> day[1] >> month[1] >> year[1];

    int fine{};
    if (year[0] != year[1]) {
        fine = (year[0] < year[1] ? 0 : 10000);
    } else {
        if (month[0] != month[1]) {
            fine = (month[0] < month[1] ? 0 : (month[0] - month[1]) * 500);
        } else {
            fine = (day[0] <= day[1] ? 0 : (day[0] - day[1]) * 15);
        }
    }

    cout << fine << endl;

    return 0;
}