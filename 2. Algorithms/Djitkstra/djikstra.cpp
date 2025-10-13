#include <bits/stdc++.h>
using namespace std;

// Dijkstra on 0-indexed graph. 
// n = number of nodes [0..n-1]
// edges: vector of (u, v, w) for building adjacency list
// returns dist vector (INF == 1e18 if unreachable)
vector<long long> dijkstra(int n, int source, const vector<tuple<int,int,long long>>& edges) {
    const long long INF = (long long)1e18;
    vector<vector<pair<int,long long>>> adj(n);
    for (auto [u, v, w] : edges) {
        // For undirected, push both directions; for directed, push only u->v
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w}); // uncomment if UNDIRECTED
    }

    vector<long long> dist(n, INF);
    dist[source] = 0;

    // min-heap of (distance, node)
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, source});

    vector<char> vis(n, 0);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5; // nodes 0..4
    // Example graph (directed):
    // 0->1 (2), 0->2 (5), 1->2 (1), 1->3 (2), 2->3 (3), 3->4 (1)
    vector<tuple<int,int,long long>> edges = {
        {0,1,2}, {0,2,5}, {1,2,1}, {1,3,2}, {2,3,3}, {3,4,1}
    };

    int source = 0;
    auto dist = dijkstra(n, source, edges);

    for (int i = 0; i < n; i++) {
        if (dist[i] >= (long long)1e18/2) cout << "dist["<<i<<"] = INF\n";
        else cout << "dist["<<i<<"] = " << dist[i] << "\n";
    }
    return 0;
}
