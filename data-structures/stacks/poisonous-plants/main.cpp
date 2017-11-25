#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    int n;
    cin >> n;

    forward_list<int> plants;
    int pesticide;
    while (--n >= 0) {
        cin >> pesticide;
        plants.push_front(pesticide);
    }

    bool more_plants_to_die = true;
    int day_passed{};
    while (more_plants_to_die) {
        more_plants_to_die = false;

        auto prev = std::begin(plants);
        auto itr = std::next(prev, 1);
        while (std::end(plants) != itr) {
            if (*itr > *prev) {
                itr = plants.erase_after(prev);
                more_plants_to_die = true;
            } else {
                ++itr;
            }
        }
        ++day_passed;
    }
    cout << day_passed << endl;

    return 0;
}