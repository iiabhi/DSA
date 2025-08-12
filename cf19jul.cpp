// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

void dfs1(int u, int p, vector<vector<int>>& adj, vector<int>& sz, vector<int>& leaves_down, vector<ll>& ops_down, vector<int>& deg) {
    sz[u] = 1;
    leaves_down[u] = (deg[u] == 1);
    ops_down[u] = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u, adj, sz, leaves_down, ops_down, deg);
        sz[u] += sz[v];
        leaves_down[u] += leaves_down[v];
        if (sz[v] > 1) {
            ops_down[u] += leaves_down[v];
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    // Check if graph is star
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == n - 1) {
            cout << 0 << "\n";
            return;
        }
    }

    vector<int> sz(n + 1);
    vector<int> leaves_down(n + 1);
    vector<ll> ops_down(n + 1, 0);

    dfs1(1, 0, adj, sz, leaves_down, ops_down, deg);

    ll min_ops = -1;
    ll total_leaves = leaves_down[1];

    for (int i = 1; i <= n; ++i) {
        ll current_ops = ops_down[i];
        if (i != 1) {
            ll parent_comp_size = n - sz[i];
            if (parent_comp_size > 1) {
                current_ops += (total_leaves - leaves_down[i]);
            }
        }
        if (min_ops == -1 || current_ops < min_ops) {
            min_ops = current_ops;
        }
    }

    cout << min_ops << "\n";
}

int main() {
    fastio
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}