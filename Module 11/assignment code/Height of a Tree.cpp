#include <bits/stdc++.h>
using namespace std;

#define int long long

int dfs(int node, vector<vector<int>>& adj) {
    int h = 0;
    for (int child : adj[node]) {
        h = max(h, dfs(child, adj));
    }
    return h + 1;  // Count this node
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> parent(n);
    vector<vector<int>> adj(n);
    int root = -1;

    for (int i = 0; i < n; ++i) {
        cin >> parent[i];
        if (parent[i] == -1) root = i;
        else adj[parent[i]].push_back(i);
    }

    cout << dfs(root, adj) << "\n";
    return 0;
}
