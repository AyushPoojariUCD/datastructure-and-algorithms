#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
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
        if (pu == pv)
            return false;
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pv] < rank[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        DisjointSet ds(n);
        int totalCost = 0;
        int edgesUsed = 0;

        for (auto &conn : connections) {
            int u = conn[0];
            int v = conn[1];
            int cost = conn[2];

            if (ds.unionByRank(u, v)) {
                totalCost += cost;
                edgesUsed++;
            }
        }

        // All cities connected if we used (n-1) edges
        return (edgesUsed == n - 1) ? totalCost : -1;
    }
};
