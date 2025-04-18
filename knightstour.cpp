#include <iostream>
#include <vector>
using namespace std;


int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};


bool isValidMove(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}


bool isValid(vector<vector<int>> &grid, int r, int c, int n, int expected) {
    if (grid[r][c] != expected)
        return false;
    if (expected == n * n - 1)
        return true;

    for (int i = 0; i < 8; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];

        if (isValidMove(nr, nc, n)) {
            if (isValid(grid, nr, nc, n, expected + 1))
                return true;
        }
    }

    return false;
}

bool checkValidGrid(vector<vector<int>> &grid) {
    int n = grid.size();
    return isValid(grid, 0, 0, n, 0); 
}

int main() {
    vector<vector<int>> grid = {
        {0, 59, 38, 33, 30, 17, 8, 63},
        {37, 34, 31, 60, 9, 62, 29, 16},
        {58, 1, 36, 39, 32, 27, 18, 7},
        {35, 48, 41, 26, 61, 10, 15, 28},
        {42, 57, 2, 49, 40, 23, 6, 19},
        {47, 50, 45, 54, 25, 20, 11, 14},
        {56, 43, 52, 3, 22, 13, 24, 5},
        {51, 46, 55, 44, 53, 4, 21, 12}
    };

    if (checkValidGrid(grid))
        cout << "Valid Knight's Tour" << endl;
    else
        cout << "Invalid Knight's Tour" << endl;

    return 0;
}
