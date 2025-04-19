/*
Path Query

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
Y will be given, you have to tell the bitwise XOR of all values of the path between 
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
6
Note:
In Example 2: The second query is (2 5). The path between 2 and 5 is 2->3->5. Value of them are (2,5). (2 xor 5 )=7 so the answer is 7.
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> adj[MAXN]; // (neighbor, edge_value)
long long xor_from_root[MAXN]; // Store XOR value from root to each node
int parent[MAXN]; // Parent of each node
int depth[MAXN]; // Depth of each node

void dfs(int node, int par, long long xor_val) {
    parent[node] = par;
    xor_from_root[node] = xor_val;
    
    for (auto& [neighbor, weight] : adj[node]) {
        if (neighbor != par) {
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor, node, xor_val ^ weight); // XOR with the current edge weight
        }
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    
    // Read the tree and edge values
    for (int i = 0; i < N - 1; ++i) {
        int a, b, v;
        cin >> a >> b >> v;
        adj[a].push_back({b, v});
        adj[b].push_back({a, v});
    }

    // Perform DFS to calculate XOR from root for each node
    xor_from_root[1] = 0; // Root node (1) has XOR value 0
    depth[1] = 0; // Root node is at depth 0
    dfs(1, -1, 0);

    // Process each query
    while (Q--) {
        int X, Y;
        cin >> X >> Y;
        
        // The result for the path between X and Y is XOR(X) ^ XOR(Y)
        long long result = xor_from_root[X] ^ xor_from_root[Y];
        cout << result << endl;
    }

    return 0;
}
