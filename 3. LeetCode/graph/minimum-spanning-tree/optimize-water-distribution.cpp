#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
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
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<vector<int>> edges = pipes;

        // Add virtual node 0 edges (building wells)
        for (int i = 1; i <= n; i++) {
            edges.push_back({0, i, wells[i - 1]});
        }

        // Sort all edges by cost
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        DisjointSet ds(n);
        int totalCost = 0;
        int edgesUsed = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], cost = e[2];
            if (ds.unionByRank(u, v)) {
                totalCost += cost;
                edgesUsed++;
            }
            if (edgesUsed == n) break; // all houses connected
        }

        return totalCost;
    }
};
