#include <iostream>
#include <cmath>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double meal_cost, tip_percent, tax_percent;
    cin >> meal_cost >> tip_percent >> tax_percent;

    double tip = meal_cost * tip_percent / 100;
    double tax = meal_cost * tax_percent / 100;
    cout << "The total meal cost is "
         << std::round(meal_cost + tip + tax)
         << " dollars." << endl;

    return 0;
}