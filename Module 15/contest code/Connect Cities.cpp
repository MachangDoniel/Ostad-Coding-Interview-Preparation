#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Read the roads
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    int components = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            ++components;
            dfs(i);
        }
    }

    cout << components - 1 << "\n";
    return 0;
}