#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;
    int components;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        components = n;
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
        if (pu == pv) return false;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pv] < rank[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }

        components--;
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n), bob(n);
        int usedEdges = 0;

        // Step 1: Use type 3 edges first (shared)
        for (auto &e : edges) {
            if (e[0] == 3) {
                bool a = alice.unionByRank(e[1], e[2]);
                bool b = bob.unionByRank(e[1], e[2]);
                if (a | b) usedEdges++;  // used if it connects at least one
            }
        }

        // Step 2: Use type 1 (Alice only)
        for (auto &e : edges) {
            if (e[0] == 1) {
                if (alice.unionByRank(e[1], e[2]))
                    usedEdges++;
            }
        }

        // Step 3: Use type 2 (Bob only)
        for (auto &e : edges) {
            if (e[0] == 2) {
                if (bob.unionByRank(e[1], e[2]))
                    usedEdges++;
            }
        }

        // Step 4: Check if both are fully connected
        if (alice.components != 1 || bob.components != 1)
            return -1;

        // Step 5: Total removable edges
        return edges.size() - usedEdges;
    }
};
