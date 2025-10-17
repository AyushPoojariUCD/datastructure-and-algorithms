class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& state) {
        if (state[u] == 1) return false; // visiting → cycle
        if (state[u] == 2) return true;  // already safe
        state[u] = 1; // mark visiting
        for (int v : graph[u]) {
            if (!dfs(v, graph, state)) return false;
        }
        state[u] = 2; // mark safe
        return true;
    }

    vector<int> dfs(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); 
        // 0 = unvisited, 1 = visiting, 2 = safe
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, state)) res.push_back(i);
        }
        return res;
    }

    vector<int> kahn(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> outdeg(V, 0);           // outdegree of each node
        vector<vector<int>> adj(V);         // reverse adjacency list

        // Build reverse graph and count outdegrees
        for (int u = 0; u < V; u++) {
            outdeg[u] = graph[u].size();    // number of outgoing edges
            for (int v : graph[u]) {
                adj[v].push_back(u);        // reverse edge: v -> u
            }
        }

        queue<int> q;

        // Nodes with 0 outgoing edges are safe
        for (int i = 0; i < V; i++) {
            if (outdeg[i] == 0) q.push(i);
        }

        vector<int> safe(V, 0);

        // Standard Kahn’s algorithm on reversed graph
        while (!q.empty()) {
            int node = q.front(); 
            q.pop();
            safe[node] = 1;                 // node is safe
            for (int prev : adj[node]) {    // for all predecessors
                if (--outdeg[prev] == 0) {  // if no outgoing edges left
                    q.push(prev);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (safe[i]) ans.push_back(i);
        }

        sort(ans.begin(), ans.end());       // ensure sorted order
        return ans;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // return dfs(graph);
        return kahn(graph);
    }
};
