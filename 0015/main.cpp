// Lattice Paths
//
// Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
// How many such routes are there through a 20×20 grid?

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int moveGrid(int x, int y, int maxX, int maxY, int *total) {
    cout << "moveGrid(" << x << ", " << y << ")" << endl;

    if (x == maxX && y == maxY) {
        *total += 1;
        return *total;
    }

    if (x < maxX)
        moveGrid(x + 1, y, maxX, maxY, total);
    if (y < maxY)
        moveGrid(x, y + 1, maxX, maxY, total);
}

int main() {
    int x = 20;
    int y = 20;
    int total = 0;

    moveGrid(0, 0, x, y, &total);
    cout << total << endl;
}
