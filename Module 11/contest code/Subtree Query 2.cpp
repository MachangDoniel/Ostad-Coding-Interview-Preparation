/*
Subtree Query 2

বাং
Problem Statement
You are given a tree with 
N
N nodes rooted at node 
1
1 and 
Q
Q queries, in each query a node 
X
X will be given you have to tell the number of leaf nodes which belong to the subtree rooted at 
X
X.

Input
The first line of input contains 
N
N and 
Q
Q. Then there are 
N
−
1
N−1 lines describing the edges. Each line contains two integers 
a
a and 
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
a
,
b
≤
N
1≤a,b≤N
Example 1:
Input:
3 2
1 2
1 3
1
2
Output:
2
1
Example 2:
Input:
5 3
1 2
2 3
3 4
3 5
1
2
5
Output:
2
2
1*/

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];  // Adjacency list for the tree
int noOfNode[MAXN];    // To store the number of leaf nodes in the subtree of each node

// DFS function to count leaf nodes in the subtree of each node
void dfs(int node, int parent) {
    // Initially consider this node as a leaf
    bool isLeaf = true;
    noOfNode[node] = 0;
    
    // Traverse all children (adjacent nodes)
    for (int child : adj[node]) {
        if (child != parent) {
            isLeaf = false;
            dfs(child, node);
            noOfNode[node] += noOfNode[child];  // Add the leaf count from the child
        }
    }

    noOfNode[node] += 1;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    // Reading the edges
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Perform DFS starting from node 1
    dfs(1, -1);

    // Answer each query
    for (int i = 0; i < Q; i++) {
        int X;
        cin >> X;
        cout << noOfNode[X] << endl;
    }

    return 0;
}