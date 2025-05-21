#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = 1e18;
vector<vector<pair<int, int>>> adj;
vector<long long> dist;

void dijkstra(int source){

    dist[1] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 1}); // {distance, node}

    while (!pq.empty()) {
        auto pp = pq.top();
        int curr_dist = pp.first;
        int u = pp.second;
        pq.pop();

        if (curr_dist > dist[u]) continue; // Skip if outdated

        for (auto pp : adj[u]) {
            int v = pp.first;
            int cost = pp.second;
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1); // {neighbor, cost}

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
    }

    dist.resize(n + 1, INF);
    dijkstra(1);

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}