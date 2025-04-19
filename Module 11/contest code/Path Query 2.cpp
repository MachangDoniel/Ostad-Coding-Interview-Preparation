/*
Path Query 2

বাং
Problem Statement
You are given a tree with 
N
N nodes, where each edge has a value 
V
i
V 
i
​
 . You are also given 
Q
Q queries, in each query two nodes 
X
X and 
Y
Y will be given, you have to tell the SUM of all values of the path between 
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
N−1 lines describing the edges. Each line contains three integers 
a
a, 
b
b and 
V
i
V 
i
​
 . There is an edge between nodes 
a
a and 
b
b and value of this edge is 
V
i
V 
i
​
 . Then there will be 
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
V
i
≤
1
0
9
1≤V 
i
​
 ≤10 
9
 
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
1 2 2
1 3 1
1 1
2 3
Output:
0
3
Example 2:
Input:
5 3
1 2 1
2 3 2
3 4 3
3 5 5
1 2
2 5
5 4
Output:
1
7
8
Note:
In Example 2: The second query is (2 5). The path between 2 and 5 is 2->3->5. Value of them are (2,5). (2 + 5 )=7 so the answer is 7.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int LOG = 17; // log2(10^5) is approximately 16.6, so we take 17

vector<pair<int, long long>> adj[MAXN]; // Adjacency list (node, edge_value)
long long sum[MAXN]; // Store cumulative sum from root to each node
int parent[MAXN][LOG], depth[MAXN];

void dfs(int node, int par, long long curr_sum) {
    parent[node][0] = par;
    sum[node] = curr_sum;
    for (int i = 1; i < LOG; i++) {
        if (parent[node][i - 1] != -1)
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        else
            break;
    }
    for (auto& [neighbor, weight] : adj[node]) {
        if (neighbor != par) {
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor, node, curr_sum + weight);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    // Bring u and v to the same depth
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

long long get_sum(int u, int lca_node) {
    return sum[u] - sum[lca_node];
}

int main() {
    int N, Q;
    cin >> N >> Q;

    // Read the tree and its edge values
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        long long v;
        cin >> a >> b >> v;
        adj[a].push_back({b, v});
        adj[b].push_back({a, v});
    }

    // Initialize parent and depth arrays
    fill(&parent[0][0], &parent[0][0] + MAXN * LOG, -1);
    depth[1] = 0;
    
    // DFS to compute LCA table and path sums
    dfs(1, -1, 0);

    // Process each query
    while (Q--) {
        int X, Y;
        cin >> X >> Y;

        int lca_node = lca(X, Y);
        long long path_sum = get_sum(X, lca_node) + get_sum(Y, lca_node);
        cout << path_sum << endl;
    }

    return 0;
}
