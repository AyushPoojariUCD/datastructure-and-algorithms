#include <bits/stdc++.h>
using namespace std;

class EulerianCircuit {
public:
    unordered_map<int, multiset<int>> adj;
    vector<int> circuit;

    void addEdge(int u, int v) {
        adj[u].insert(v);
        adj[v].insert(u); // undirected graph
    }

    void dfs(int u) {
        while (!adj[u].empty()) {
            int v = *adj[u].begin();
            adj[u].erase(adj[u].find(v));
            adj[v].erase(adj[v].find(u));
            dfs(v);
        }
        circuit.push_back(u);
    }

    vector<int> getEulerianCircuit(int start) {
        dfs(start);
        reverse(circuit.begin(), circuit.end());
        return circuit;
    }
};
