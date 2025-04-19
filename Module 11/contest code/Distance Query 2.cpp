/*
Distance Query 2

বাং
Problem Statement
You are given a tree with 
N
N nodes. You are also given 
Q
Q queries, in each query one node 
X
X will be given, you have to tell the Maximum Distance between 
X
X and other nodes.

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
Q lines each containing one integer 
X
X.

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
1
2
Output:
1
2
Example 2:
Input:
6 3
1 2
2 3
3 4
3 5
2 6
2
3
5
Output:
2
2
3
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOG = 17; // log2(10^5) is approximately 16.6, so we take 17

vector<int> adj[MAXN]; // Adjacency list for the tree
vector<int> dist_from_A(MAXN), dist_from_B(MAXN); // Distances from nodes A and B

// DFS function to compute the distance
void dfs(int node, int parent, vector<int>& dist, const vector<int> adj[]) {
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dist[neighbor] = dist[node] + 1;
            dfs(neighbor, node, dist, adj);
        }
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    // Read the tree structure and build the adjacency list
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); // Add b to a's list
        adj[b].push_back(a); // Add a to b's list
    }

    // Step 1: Perform DFS from an arbitrary node (node 1)
    vector<int> dist_from_1(N + 1, 0);
    dfs(1, -1, dist_from_1, adj);  // DFS to calculate distances from node 1
    
    // Step 2: Find the farthest node from node 1 (let's call it node A)
    int A = 1;
    for (int i = 2; i <= N; ++i) {
        if (dist_from_1[i] > dist_from_1[A]) {
            A = i;
        }
    }

    // Step 3: Perform DFS from node A to calculate distances from A
    dist_from_A.assign(N + 1, 0);
    dfs(A, -1, dist_from_A, adj);  // DFS from node A

    // Step 4: Find the farthest node from node A (let's call it node B)
    int B = A;
    for (int i = 1; i <= N; ++i) {
        if (dist_from_A[i] > dist_from_A[B]) {
            B = i;
        }
    }

    // Step 5: Perform DFS from node B to calculate distances from B
    dist_from_B.assign(N + 1, 0);
    dfs(B, -1, dist_from_B, adj);  // DFS from node B

    // Step 6: Answer each query
    while (Q--) {
        int X;
        cin >> X;
        // The maximum distance from X is the maximum of dist_from_A[X] and dist_from_B[X]
        cout << max(dist_from_A[X], dist_from_B[X]) << endl;
    }

    return 0;
}
