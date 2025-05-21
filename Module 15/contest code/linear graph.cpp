#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200005;
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

    if (m != n - 1) {
        cout << "No\n";
        return 0;
    }

    vector<int> degree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // Check degree constraints
    int deg1 = 0;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] > 2) {
            cout << "No\n";
            return 0;
        }
        if (degree[i] == 1) deg1++;
    }

    if (deg1 != 2) {
        cout << "No\n";
        return 0;
    }

    // Check if graph is connected
    dfs(1);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}