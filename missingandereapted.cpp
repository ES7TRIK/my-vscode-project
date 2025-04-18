#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findMissingAndRepeatedNumbers(vector<vector<int>>& grid) {
    int n = grid.size();
    unordered_set<int> s;
    int repeated = -1, missing = -1;

    // Flatten the grid into a single array
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nums.push_back(grid[i][j]);
        }
    }

    // Find repeated number
    for (int num : nums) {
        if (s.find(num) != s.end()) {
            repeated = num;
        } else {
            s.insert(num);
        }
    }

    // Find missing number
    for (int i = 1; i <= n * n; i++) {
        if (s.find(i) == s.end()) {
            missing = i;
            break;
        }
    }

    return {repeated, missing};
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 8} // Example where '8' is repeated, and '9' is missing
    };

    vector<int> result = findMissingAndRepeatedNumbers(grid);
    cout <<
} 