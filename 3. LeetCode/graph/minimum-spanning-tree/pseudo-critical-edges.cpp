#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    bool unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return false;
        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pv] < rank[pu]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

class Solution {
private:
    // Build MST and return total cost
    int kruskal(int n, vector<vector<int>>& edges, int skipEdge = -1, int pickEdge = -1) {
        DisjointSet ds(n);
        int total = 0, edgesUsed = 0;

        if (pickEdge != -1) {
            // Include this edge first
            total += edges[pickEdge][2];
            ds.unionByRank(edges[pickEdge][0], edges[pickEdge][1]);
            edgesUsed++;
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == skipEdge) continue; // skip this edge
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (ds.unionByRank(u, v)) {
                total += w;
                edgesUsed++;
            }
        }

        return (edgesUsed == n - 1) ? total : INT_MAX;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // Step 1: Append original indices
        for (int i = 0; i < edges.size(); i++) edges[i].push_back(i);

        // Step 2: Sort edges by weight
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        // Step 3: Find MST base cost
        int baseCost = kruskal(n, edges);

        vector<int> critical, pseudo;

        // Step 4: Test each edge
        for (int i = 0; i < edges.size(); i++) {
            int withoutEdge = kruskal(n, edges, i, -1);
            if (withoutEdge > baseCost) {
                critical.push_back(edges[i][3]);
            } else {
                int withEdge = kruskal(n, edges, -1, i);
                if (withEdge == baseCost)
                    pseudo.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};
