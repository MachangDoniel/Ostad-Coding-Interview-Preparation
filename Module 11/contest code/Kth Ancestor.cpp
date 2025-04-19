/*
Kth Ancestor

বাং
Problem Statement
You are given a tree with 
N
N nodes. You are also given 
Q
Q queries, in each query one node 
X
X and an integer 
K
K will be given, you have to tell the Kth Ancestor of 
X
X.

If the node doesn't have 
k
kth ancestor then print -1.
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
a, 
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
K
K.

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
K
,
a
,
b
≤
N
1≤X,K,a,b≤N
Example 1:
Input:
3 2
1 2
1 3
1 1
2 1
Output:
-1
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
5 1
Output:
-1
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

int kthAncestor(int X, int K) {
    // Process each bit of K
    for (int i = LOG - 1; i >= 0; i--) {
        if (K >= (1 << i)) {
            X = parent[X][i];
            if (X == -1) return -1; // If we run out of ancestors
            K -= (1 << i);
        }
    }
    return X;
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
        int X, K;
        cin >> X >> K;
        cout << kthAncestor(X, K) << endl;
    }

    return 0;
}
