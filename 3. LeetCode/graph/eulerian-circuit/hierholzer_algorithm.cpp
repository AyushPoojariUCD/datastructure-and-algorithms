/*
Algorithm to Find Eulerian Circuit (Hierholzer’s Algorithm)
Hierholzer’s Algorithm efficiently finds an Eulerian circuit in O(E) time.
*/

#include <bits/stdc++.h>
using namespace std;

class EulerianCircuit {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& circuit) {
        while (!adj[u].empty()) {
            int v = adj[u].back();
            adj[u].pop_back();
            dfs(v, adj, circuit);
        }
        circuit.push_back(u);
    }

    vector<int> findEulerianCircuit(vector<vector<int>>& adj, int start) {
        vector<int> circuit;
        dfs(start, adj, circuit);
        reverse(circuit.begin(), circuit.end());
        return circuit;
    }
};