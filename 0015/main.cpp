// Lattice Paths
//
// Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
// How many such routes are there through a 20×20 grid?

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int moveGrid(int x, int y, int maxX, int maxY, int *total, unordered_map<string, int> *countByPosition) {
    cout << "moveGrid(" << x << ", " << y << ")" << endl;

    string position = to_string(x) + "," + to_string(y);
    unordered_map<string, int>::const_iterator got = countByPosition->find(position);

    if (got != countByPosition->end()) {
        cout << "found stored " << position << " = " << got->second << endl;
        *total += got->second;
        return *total;
    } else if (x == maxX && y == maxY) {
        *total += 1;
        return *total;
    }

    int result;
    if (x < maxX) {
        result = moveGrid(x + 1, y, maxX, maxY, total, countByPosition);
        cout << "store " << position << " = " << result << endl;
        countByPosition->insert({position, result});
    }
    if (y < maxY) {
        result = moveGrid(x, y + 1, maxX, maxY, total, countByPosition);
        cout << "store " << position << " = " << result << endl;
        countByPosition->insert({position, result});
    }
}

int main() {
    int x = 1;
    int y = 1;
    int total = 0;
    unordered_map<string, int> countByPosition;

    moveGrid(0, 0, x, y, &total, &countByPosition);
    cout << total << endl;
}
