#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // DFS -> Time: O(V+E)
    void dfsRec(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) dfsRec(it, adj, vis, st);
        }
        st.push(node);
    }
    
    vector<int> dfs(int V, vector<vector<int>>& edges){
        stack<int> st;
        vector<int> adj[V];
        vector<int> vis(V, 0);
        
        for(auto e: edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) dfsRec(i, adj, vis, st);
        }

        vector<int> topo;
        
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }
        
        return topo;
    }
    
    // Kahn Algorithm -> Time: O(V+E)
    vector<int> kahn(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        vector<int> topo;
        vector<int> indegree(V,0);
        
        for(auto e: edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto nei: adj[node]){
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }
        
        return topo;
    }

public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // return dfs(V, edges);
        return kahn(V, edges);
    }
};
