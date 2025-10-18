#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]); // Path compression
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
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Step 1: Sort edges based on weight
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        // Step 2: Initialize Disjoint Set
        DisjointSet ds(V);
        int mstWeight = 0;
        int edgesUsed = 0;

        // Step 3: Pick edges one by one
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (ds.findUPar(u) != ds.findUPar(v)) {
                mstWeight += wt;
                ds.unionByRank(u, v);
                edgesUsed++;
                if (edgesUsed == V - 1) break;
            }
        }

        return mstWeight;
    }
};
