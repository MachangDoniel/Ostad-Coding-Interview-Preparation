// 🧠 Problem: Multiversal Portal Network: Last Safe Haven

// 🌀 Problem Statement

// In the multiverse, there are N universes, each connected to others through one-way portals. You start your journey in universe 1 and aim to reach universe N, the only universe that will never be destroyed.

// Each universe (except N) will self-destruct at a given time, specified in a list destroy_time[i]. Once a universe is destroyed, you can no longer enter or pass through it.

// You start at time = 0 and traveling through any portal takes exactly 1 second.

// Your task is to determine whether there's any safe path from universe 1 to universe N, such that:

//     You never enter a destroyed universe.

//     You arrive at each universe strictly before it is destroyed.

//     You reach universe N at any time (it never gets destroyed).

// 📥 Input Format

//     First line: Two integers n and m — number of universes and portals (2 ≤ n ≤ 10⁵, 1 ≤ m ≤ 2×10⁵)

//     Next line: n-1 integers — destroy_time[1] to destroy_time[n-1] (1 ≤ destroy_time[i] ≤ 10⁹), where destroy_time[i] is the time universe i+1 will be destroyed

//     Next m lines: Each contains two integers u and v — a one-way portal from universe u to universe v (1 ≤ u, v ≤ n)

// 📤 Output Format

//     Print "YES" if there's a path from universe 1 to n such that you can reach before any intermediate universe is destroyed

//     Otherwise, print "NO"

// 🔍 Example Input 1

// 4 4
// 3 3 10
// 1 2
// 2 3
// 3 4
// 1 3

// ✅ Output 1

// YES

// 🔍 Example Input 2

// 4 3
// 1 1 1
// 1 2
// 2 3
// 3 4

// ❌ Output 2

// NO

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> destroy_time(n, 1e9); // default destruction time is INF
    for (int i = 1; i < n; ++i)
        cin >> destroy_time[i]; // nth universe has no destroy time

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q; // {universe, current_time}

    q.push({1, 0});
    visited[1] = true;

    while (!q.empty()) {
        auto [u, time] = q.front(); q.pop();
        if (u == n) {
            cout << "YES" <<endl;
            return 0;
        }
        for (int v : adj[u]) {
            if (!visited[v]) {
                int arrival = time + 1;
                if (v == n || arrival < destroy_time[v]) {
                    visited[v] = true;
                    q.push({v, arrival});
                }
            }
        }
    }

    cout << "NO\n";
    return 0;
}
