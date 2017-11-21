#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
private:
    vector<int> elements;

public:
    int maximumDifference;

    Difference(vector<int> ele) : elements{std::move(ele)} {}

    void computeDifference() {
        int num_max{elements[0]}, num_min{elements[0]};
        for (auto i = std::begin(elements) + 1; i != std::end(elements); ++i) {
            num_max = (num_max >= *i ? num_max : *i);
            num_min = (num_min <= *i ? num_min : *i);
        }

        maximumDifference = std::abs(num_max - num_min);
    }
}; // End of Difference class

int main() {
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}
