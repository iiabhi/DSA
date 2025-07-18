// #include <bits/stdc++.h>
#include <vector>
#include<iostream>
using namespace std;

int arrangeCoins(int n) {
    long long low = 0, high = n, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        long long curr = mid * (mid + 1) / 2;
        if (curr == n) return mid;
        else if (curr < n) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}

int main() {
    int t;
    cin >> t;
    vector<int> coins(t);
    for (int i = 0; i < t; i++) {
        cin >> coins[i];
    }

    for (int i = 0; i < t; i++) {
        cout << arrangeCoins(coins[i]) << endl;
    }

    return 0;
}
