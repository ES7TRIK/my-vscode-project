#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int>& arr, int n, int m, int maxAllowed) {
    int students = 1, pages = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowed) 
        return false;
        if (pages + arr[i] <= maxAllowed) 
        pages += arr[i];
        else {
            students++;
            pages = arr[i];
            if (students > m) 
            return false;
        }
    }
    return true;
}

int bookAllocation(vector<int>& arr, int n, int m) {
    if (m > n) 
    return -1;
    int sum = 0, start = 0, ans = -1;
    for (int i = 0; i < n; i++) 
    sum += arr[i];
    int end = sum;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isValid(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else start = mid + 1;
    }
    return ans;
}

int main() {
    vector<int> books = {10, 20, 30, 40};
    int students = 2;
    int n = books.size();
    cout << bookAllocation(books, n, students) << endl;
    return 0;
}
