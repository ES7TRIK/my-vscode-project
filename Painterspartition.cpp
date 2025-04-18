#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int maxallowed) {
    int painters = 1, time = 0;
    for (int i = 0; i < n; i++) {
        if (time + arr[i] <= maxallowed) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];
            if (painters > m) // Should be `>`, not `<`
                return false;
        }
    }
    return painters <= m;
}

int mintimetoprint(vector<int>& arr, int n, int m) {
    int sum = 0, maxVal = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int st = maxVal, end = sum, ans = -1;
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (isPossible(arr, n, m, mid)) { // Fix function call
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter number of boards: ";
    cin >> n;
    cout << "Enter number of painters: ";
    cin >> m;

    vector<int> arr(n);
    cout << "Enter the lengths of the boards: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Minimum time to paint all boards: " << mintimetoprint(arr, n, m) << endl;
    return 0;
}
