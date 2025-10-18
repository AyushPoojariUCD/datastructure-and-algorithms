#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<pair<int, int>> adj[V];
        for (auto &e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Step 2: Initialize
        vector<int> vis(V, 0);
        // Min-heap -> {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int mstWt = 0;

        // Step 3: Run Prim’s Algorithm
        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            // Skip if already visited
            if (vis[node]) continue;
            vis[node] = 1;
            mstWt += wt;

            // Explore adjacent edges
            for (auto &[adjNode, edgeWt] : adj[node]) {
                if (!vis[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }

        return mstWt;
    }
};
