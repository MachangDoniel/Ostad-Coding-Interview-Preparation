// 🌲 Problem 2: Forest Power Grid (Prim’s Algorithm)
// 🧩 Problem Statement

// You are in charge of setting up an electrical power grid between n forest outposts using m potential underground cables. Each cable connects two outposts and has a cost to install.

// Your task is to connect all outposts with the minimum total cost, ensuring that power can reach every outpost from any other (i.e., build a connected network). If it's not possible to connect all outposts, print -1.
// 🧾 Input Format

// n m
// u1 v1 w1
// u2 v2 w2
// ...
// um vm wm

//     n: number of outposts (1 ≤ n ≤ 10⁵)

//     m: number of cables (1 ≤ m ≤ 2×10⁵)

//     ui, vi: endpoints of a cable

//     wi: cost of laying the cable

// 📤 Output Format

// Minimum total cost of connecting all outposts or -1 if impossible

// 📘 Sample Input

// 4 4
// 1 2 5
// 2 3 6
// 3 4 2
// 4 1 3

// 📗 Sample Output

// 10

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> inMST(n + 1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int totalCost = 0, edgesUsed = 0;

    pq.push({0, 1});

    while (!pq.empty() && edgesUsed < n) {
        auto [cost, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        totalCost += cost;
        edgesUsed++;

        for (auto [v, w] : adj[u]) {
            if (!inMST[v]) {
                pq.push({w, v});
            }
        }
    }

    if (edgesUsed == n)
        cout << totalCost << endl;
    else
        cout << -1 << endl;

    return 0;
}
