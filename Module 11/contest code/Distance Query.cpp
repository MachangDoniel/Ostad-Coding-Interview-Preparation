/*
Distance Query

বাং
Problem Statement
You are given a tree with 
N
N nodes. You are also given 
Q
Q queries, in each query two nodes 
X
X and 
Y
Y will be given, you have to tell the Distance between 
X
X and 
Y
Y.

Input
The first line of input contains 
N
N and 
Q
Q.Then there are 
N
−
1
N−1 lines describing the edges. Each line contains two integers 
a
a, and 
b
b. There is an edge between nodes 
a
a and 
b
b. Then there will be 
Q
Q lines each containing two integers 
X
X and 
Y
Y.

Output
Print the answer of each query.

Constraints
2
2 
≤
≤ 
N
,
Q
N,Q 
≤
≤ 
1
0
5
10 
5
 
1
≤
X
,
Y
,
a
,
b
≤
N
1≤X,Y,a,b≤N
Example 1:
Input:
3 2
1 2
1 3
1 1
2 1
Output:
0
1
Example 2:
Input:
6 3
1 2
2 3
3 4
3 5
2 6
2 2
3 2
5 6
Output:
0
1
3
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
    parent[node][0] = par; // Set immediate parent
    for (int i = 1; i < LOG; i++) {
        if (parent[node][i - 1] != -1) {
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        } else {
            break;
        }
    }
    for (int neighbor : adj[node]) {
        if (neighbor != par) {
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor, node);
        }
    }
}

int lca(int u, int v) {
    // Bring u and v to the same depth
    if (depth[u] < depth[v]) swap(u, v);
    
    // Lift u to the same level as v
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = parent[u][i];
        }
    }

    // If they are the same, return the node
    if (u == v) return u;

    // Lift both u and v until they meet
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    // The parent of u (or v) is the LCA
    return parent[u][0];
}

int main() {
    int N, Q;
    cin >> N >> Q;

    // Read the tree structure
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Initialize parent array
    fill(&parent[0][0], &parent[0][0] + MAXN * LOG, -1);
    depth[1] = 0; // Set root node depth
    dfs(1, -1); // Perform DFS to populate parent and depth arrays

    // Answer each query
    while (Q--) {
        int X, Y;
        cin >> X >> Y;

        int lca_node = lca(X, Y);
        int distance = depth[X] + depth[Y] - 2 * depth[lca_node];
        cout << distance << endl;
    }

    return 0;
}
