#include <iostream>
#include <string>

using namespace std;


bool is_palindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}


bool is_special(string s) {
    int cnt[10] = {0};
    for (char c : s) {
        cnt[c - '0']++;
    }
    
    if (cnt[0] > 0) return false;
    for (int d = 1; d <= 9; d++) {
        if (cnt[d] > 0 && cnt[d] != d) 
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;
        for (long long x = N + 1; ; x++) {
            string s = to_string(x);
            if (is_palindrome(s) && is_special(s)) {
                cout << s << "\n";
                break;
            }
        }
    }
    return 0;
}
