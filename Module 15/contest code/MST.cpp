// Kruskal Algo

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;

int parent[MAXN], sz[MAXN];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // path compression
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b)
        return false;
    if (sz[a] < sz[b])
        swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; ++i)
        make_set(i);

    long long mst_weight = 0;
    for (auto& e : edges) {
        if (union_sets(e.u, e.v))
            mst_weight += e.w;
    }

    cout << mst_weight << endl;
    return 0;
}




// Prim's algo
// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// const int MAXN = 1e5 + 5;
// vector<pair<int, int>> adj[MAXN]; // adj[u] = {weight, v}
// bool visited[MAXN];

// int main() {
//     int n, m;
//     cin >> n >> m;

//     for (int i = 0; i < m; ++i) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].emplace_back(w, v);
//         adj[v].emplace_back(w, u);
//     }

//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//     pq.push({0, 1}); // start from node 1

//     long long mst_weight = 0;

//     while (!pq.empty()) {
//         auto [w, u] = pq.top();
//         pq.pop();

//         if (visited[u])
//             continue;
//         visited[u] = true;
//         mst_weight += w;

//         for (auto& [next_w, v] : adj[u]) {
//             if (!visited[v])
//                 pq.push({next_w, v});
//         }
//     }

//     cout << mst_weight << endl;
//     return 0;
// }