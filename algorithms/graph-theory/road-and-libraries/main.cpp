#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief   an implementation of Union-Find algorithm
 * @note    Each disjoint set is treated as a tree, whose root is indexed by the root element
 *      and the value of the root element is the height of the tree
 * */
class UnionFindOJ {
public:
    /**
     * @brief   Construct the disjosize_t sets.
     * @param numElements  the initial number of disjosize_t sets
     * */
    UnionFindOJ(size_t numElements) : sets(numElements, -1) {}

    /**
     * @brief Perform a find with path compression.
     * @return the set containing x
     * */
    size_t find(size_t x) {
        if (x >= sets.size()) {
            return -1;
        }

        if (sets[x] < 0) {
            return x;
        } else {
            return sets[x] = find(sets[x]);
        }
    }

    /**
     * @brief   union the containing sets of 2 elements
     * @param i index of an element
     * @param j index of another element
     * */
    void unionSets(const size_t x, const size_t y) {
        // find set for x
        size_t root1 = find(x);
        // find set for y
        size_t root2 = find(y);

        if (sets[root1] < sets[root2]) {  // root2 is deeper
            sets[root1] = root2;   // make root2 the new root
        } else {
            if (sets[root1] == sets[root2]) {
                --sets[root1]; // increment the height for set root1
            }

            sets[root2] = root1;   // make root1 the new root
        }
    }

    /**
     * @brief   get the number of elements in all disjoint sets
     * */
    size_t size() const {
        return sets.size();
    }

    size_t nDisjointSets() const {
        size_t n{};

        for (const auto &s:sets) {
            if (s < 0) {
                ++n;
            }
        }

        return n;
    }

private:
    std::vector<int> sets;
};

int main() {
    // q: # of queries
    int q;
    // n: # of cities
    // m: # of roads
    // cost_lib: cost to build a library
    // cost_road: cost to repiar a road
    int n, m, cost_lib, cost_road;
    // city u is connected to city v
    size_t u, v;

    cin >> q;
    while (q--) {
        cin >> n >> m >> cost_lib >> cost_road;

        if (cost_lib <= cost_road) {
            cout << cost_lib * n << endl;
            continue;
        }

        // records of connected components
        UnionFindOJ UF(m + 1);

        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            UF.unionSets(u, v);
        }

        int num_connected_component = UF.nDisjointSets();
        --num_connected_component;

        cout << (cost_lib * num_connected_component + cost_road * (m - num_connected_component + 1)) << endl;
    }


    return 0;
}