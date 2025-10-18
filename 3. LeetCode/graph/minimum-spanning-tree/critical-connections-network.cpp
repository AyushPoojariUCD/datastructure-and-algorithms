class Solution {
public:
    int timer = 1;
    vector<vector<int>> res;

    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc, vector<int>& low, vector<bool>& vis) {
        vis[u] = true;
        disc[u] = low[u] = timer++;
        for (int v : adj[u]) {
            // ignore the edge to parent node
            if (v == parent) continue; 
            if (!vis[v]) {
                // DFS to the neighbor
                dfs(v, u, adj, disc, low, vis);
                // update low value of u
                low[u] = min(low[u], low[v]);
                // Bridge condition
                if (low[v] > disc[u])
                    res.push_back({u, v});
            }
            else {
                // If neighbor is already visited and not parent → back edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto &edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> disc(n, -1), low(n, -1);
        vector<bool> vis(n, false);
        dfs(0, -1, adj, disc, low, vis);
        return res;
    }
};
