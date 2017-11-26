#include <iostream>

using namespace std;

class AdvancedArithmetic {
public:
    virtual int divisorSum(int n)=0;
};

class Calculator : public AdvancedArithmetic {
public:
    int divisorSum(int n) {
        int divisor_sum{};
        for (int i = n / 2; i >= 1; --i) {
            if (0 == n % i) {
                divisor_sum += i;
            }
        }

        divisor_sum += n;
        return divisor_sum;
    }
};

int main() {
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator();
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;
    return 0;
}
