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
        return parent[node] = findUPar(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pv] < rank[pu]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Step 1: Check if we have enough cables
        if (connections.size() < n - 1)
            return -1;

        // Step 2: Initialize DSU
        DisjointSet ds(n);

        // Step 3: Union all connections
        for (auto &conn : connections) {
            int u = conn[0], v = conn[1];
            ds.unionByRank(u, v);
        }

        // Step 4: Count number of connected components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i)
                components++;
        }

        // Step 5: Operations required = components - 1
        return components - 1;
    }
};
