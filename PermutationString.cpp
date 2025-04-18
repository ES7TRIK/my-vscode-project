#include <iostream>
#include <vector>
using namespace std;

bool permutationString(string s1, string s2) {
    if (s1.length() > s2.length()) return false;

    vector<int> countS1(26, 0), countS2(26, 0);

    for (char c : s1) countS1[c - 'a']++;
    for (int i = 0; i < s1.length(); i++) countS2[s2[i] - 'a']++;

    if (countS1 == countS2) return true;

    for (int i = s1.length(); i < s2.length(); i++) {
        countS2[s2[i] - 'a']++;
        countS2[s2[i - s1.length()] - 'a']--;

        if (countS1 == countS2) return true;
    }

    return false;
}

int main() {
    string s1 = "ab", s2 = "eidbaooo";
    cout << (permutationString(s1, s2) ? "true" : "false") << endl;
    return 0;
}
