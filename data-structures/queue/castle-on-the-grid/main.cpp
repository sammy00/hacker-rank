#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Grid {
    // true for horizontal, false for vertical
    int horizontal;
    int x;
    int y;
    int num_moves;

    Grid() {}

    Grid(int horizontal_, int x_, int y_) : horizontal{horizontal_}, x{x_}, y{y_} {}

    Grid(int horizontal_, int x_, int y_, int num_moves_) : horizontal{horizontal_}, x{x_}, y{y_},
                                                            num_moves{num_moves_} {}
};

int main() {
    int n;
    cin >> n;

    vector<vector<char>> maze(n, vector<char>(n));
    for (auto &row : maze) {
        for (auto &cell : row) {
            cin >> cell;
        }
    }

    int x0, y0, x, y;
    cin >> x0 >> y0 >> x >> y;
    queue<Grid> grids;
    grids.emplace(false, x0, y0, 0);

    maze[y0][x0] = 'X';
    auto extra = 1;
    Grid cell;
    while (!grids.empty()) {
        auto g = grids.front();
        grids.pop();

        // top
        cell.x = g.x;
        cell.y = g.y - 1;
        if ((cell.y >= 0) && ('.' == maze[cell.y][cell.x])) {
            auto num_moves = g.horizontal ? (g.num_moves + 1) : g.num_moves;

        }
    }


    return 0;
}