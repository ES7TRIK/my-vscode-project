#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>>& mat, int r, int c, string path, vector<string>& ans, vector<vector<bool>>& vis) {
    int n = mat.size(); // Corrected 'match.size()' to 'mat.size()'
    
    // 🔴 Base cases: Check for out-of-bounds, obstacles (0), or visited cells
    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || vis[r][c]) {
        return;
    }

    // ✅ If we reached the bottom-right corner, store the path
    if (r == n - 1 && c == n - 1) {
        ans.push_back(path);
        return;
    }

    // 🔴 Mark cell as visited
    vis[r][c] = true;

    // ✅ Move in all 4 directions: Down (D), Left (L), Right (R), Up (U)
    helper(mat, r + 1, c, path + "D", ans, vis);  // Down
    helper(mat, r, c - 1, path + "L", ans, vis);  // Left
    helper(mat, r, c + 1, path + "R", ans, vis);  // Right
    helper(mat, r - 1, c, path + "U", ans, vis);  // Up

    // 🔴 Unmark cell (Backtracking)
    vis[r][c] = false;
}

// ✅ Function to find paths from (0,0) to (n-1,n-1)
vector<string> findPath(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<string> ans;
    string path = "";
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    // Only start if the starting point is open (1)
    if (mat[0][0] == 1) {
        helper(mat, 0, 0, path, ans, vis);
    }

    return ans;
}

// ✅ Test the function
int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    vector<string> paths = findPath(maze);
    
    if (paths.empty()) {
        cout << "No path found" << endl;
    } else {
        cout << "Possible Paths:" << endl;
        for (string path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}
