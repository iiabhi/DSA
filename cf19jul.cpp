#include <iostream>


using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define MOD 1000000007
typedef long long ll;

long long findPow(long long a, long long b) {
    if(b == 0) return 1;
    long long half = findPow(a, b/2);
    long long result = (half * half) % MOD;
    if(b%2 ==1) result = (result*a) % MOD;
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<ll,ll>> ip(n);
    vector<pair<ll,ll>> tr(n);
    for(int i = 0; i < n; i++) {
        cin >> ip[i].first >> ip[i].second >> tr[i].first >> tr[i].second;
    }
    vector<pair<ll,ll>> change(n, pair<ll,ll>({0,0}));
    for(int i = 0; i < n; i++) {
        change[i].first = tr[i].first - ip[i].first;
        change[i].second = tr[i].second - ip[i].second;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(change[i].second < 0) {
            ans += abs(change[i].second) + (ip[i].first - abs(min(change[i].first, (ll)0)));
        }
        if(change[i].first < 0) {
            ans += abs(change[i].first);
        }
    }
    cout << ans << endl;


}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}