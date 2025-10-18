#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs1(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (int v : adj[node]) {
            if (!vis[v])
                dfs1(v, adj, vis, st);
        }
        st.push(node); // store node after finishing
    }

    void dfs2(int node, vector<int> adjT[], vector<int>& vis, vector<int>& scc) {
        vis[node] = 1;
        scc.push_back(node);
        for (int v : adjT[node]) {
            if (!vis[v])
                dfs2(v, adjT, vis, scc);
        }
    }

public:
    vector<vector<int>> kosaraju(int V, vector<int> adj[]) {
        stack<int> st;
        vector<int> vis(V, 0);

        // Step 1: Order nodes by finish time
        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs1(i, adj, vis, st);
        }

        // Step 2: Transpose the graph
        vector<int> adjT[V];
        for (int u = 0; u < V; u++) {
            for (int v : adj[u])
                adjT[v].push_back(u);
        }

        // Step 3: DFS on Transposed Graph in stack order
        fill(vis.begin(), vis.end(), 0);
        vector<vector<int>> sccs;

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                vector<int> scc;
                dfs2(node, adjT, vis, scc);
                sort(scc.begin(), scc.end());
                sccs.push_back(scc);
            }
        }

        sort(sccs.begin(), sccs.end());
        return sccs;
    }
};
