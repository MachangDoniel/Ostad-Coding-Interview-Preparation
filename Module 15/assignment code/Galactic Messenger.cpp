// 🔥 Problem 1: Galactic Messenger (Dijkstra’s Algorithm)
// 🧩 Problem Statement

// In a galaxy of n planets connected by m unidirectional hyperspace tunnels, a messenger droid starts at planet 1 and must send messages to all other planets. Each tunnel takes some time to travel, and the goal is to minimize the time it takes to reach each planet.

// You are given the time w it takes to travel through each tunnel from planet u to planet v.

// Your task is to calculate the minimum travel time from planet 1 to every other planet. If a planet is unreachable, return -1 for it.

// 🧾 Input Format

// n m
// u1 v1 w1
// u2 v2 w2
// ...
// um vm wm

//     n: number of planets (1 ≤ n ≤ 10^⁵)

//     m: number of tunnels (1 ≤ m ≤ 2×10^⁵)

//     ui, vi: tunnel from ui to vi

//     wi: time to traverse the tunnel (1 ≤ wi ≤ 10^⁴)

// 📤 Output Format

// n space-separated integers representing minimum times from planet 1 to 1 through n
// (0 for planet 1, -1 for unreachable planets)

// 📘 Sample Input

// 5 6
// 1 2 3
// 1 3 6
// 2 3 2
// 2 4 5
// 3 5 1
// 4 5 2

// 📗 Sample Output

// 0 3 5 8 6

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
typedef pair<int, int> pii;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n + 1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (dist[i] == INF ? -1 : dist[i]) << " ";
    }
    cout << endl;
    return 0;
}
