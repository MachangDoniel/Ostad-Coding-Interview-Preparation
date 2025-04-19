/*
Path Query 3
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int LOG = 17; // log2(10^5) is approximately 16.6, so we take 17

vector<int> adj[MAXN];
int parent[MAXN][LOG], depth[MAXN];

void dfs(int node, int par) {
    parent[node][0] = par;
    for (int i = 1; i < LOG; i++) {
        if (parent[node][i - 1] != -1)
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        else
            break;
    }
    for (int neighbor : adj[node]) {
        if (neighbor != par) {
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor, node);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    // Bring u and v to the same level
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = parent[u][i];
        }
    }

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

vector<int> get_path(int u, int v) {
    vector<int> path;
    int common_ancestor = lca(u, v);
    
    // Path from u to LCA
    while (u != common_ancestor) {
        path.push_back(u);
        u = parent[u][0];
    }
    path.push_back(common_ancestor);

    // Path from v to LCA (reverse it to get from LCA to v)
    vector<int> path_v;
    while (v != common_ancestor) {
        path_v.push_back(v);
        v = parent[v][0];
    }

    // Combine the paths
    reverse(path_v.begin(), path_v.end());
    path.insert(path.end(), path_v.begin(), path_v.end());

    return path;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    
    // Read the tree
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // DFS to fill parent, depth and prepare binary lifting
    fill(&parent[0][0], &parent[0][0] + MAXN * LOG, -1);
    depth[1] = 0;
    dfs(1, -1);

    // Process queries
    while (Q--) {
        int X, Y, K;
        cin >> X >> Y >> K;

        // Get the path between X and Y
        vector<int> path = get_path(X, Y);
        
        // Check if the Kth node exists in the path
        if (K <= path.size()) {
            cout << path[K - 1] << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
