#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to check if `sub` is a subsequence of `x`
bool isSubsequence(const string& sub, const string& x) {
    int i = 0, j = 0;
    while (i < sub.size() && j < x.size()) {
        if (sub[i] == x[j]) i++;
        j++;
    }
    return i == sub.size();
}

// Function to find longest subsequence of x which is also a substring of y
int longestSubsequence(string x, string y) {
    int maxLen = 0;
    int n = y.size();

    for (int i = 0; i < n; ++i) {
        string sub = "";
        for (int j = i; j < n; ++j) {
            sub += y[j];
            if (isSubsequence(sub, x)) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

int main() {
    string x, y;
    cin >> x >> y;

    int result = longestSubsequence(x, y);
    cout << result << endl;

    return 0;
}
