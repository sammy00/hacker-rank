#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    // Declare second integer, double, and String variables.
    int mi;
    double md;
    string ms;

    // Read and save an integer, double, and String to your variables.
    cin >> mi >> md;
    // ignore the trailing newline from cin
    cin.ignore();
    std::getline(cin, ms);

    // Print the sum of both integer variables on a new line.
    cout << i + mi << endl;

    // Print the sum of the double variables on a new line.
    cout << std::fixed << std::setprecision(1) << d + md << endl;

    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    cout << s + ms << endl;

    return 0;
}