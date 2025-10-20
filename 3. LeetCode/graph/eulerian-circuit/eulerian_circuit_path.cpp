class Solution {
  public:
    // DFS utility to check connectivity
    void dfs(int u, vector<int> adj[], vector<bool>& visited) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v])
                dfs(v, adj, visited);
        }
    }

    // Check if graph is connected ignoring isolated vertices
    bool isConnected(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        int start = -1;

        // Find a vertex with non-zero degree to start DFS
        for (int i = 0; i < V; i++) {
            if (!adj[i].empty()) {
                start = i;
                break;
            }
        }

        // If all vertices have 0 degree, graph is trivially Eulerian
        if (start == -1)
            return true;

        // DFS traversal
        dfs(start, adj, visited);

        // Check if all non-zero degree vertices are visited
        for (int i = 0; i < V; i++) {
            if (!adj[i].empty() && !visited[i])
                return false;
        }

        return true;
    }

    int isEulerCircuit(int V, vector<int> adj[]) {
        // Check if graph is connected
        if (!isConnected(V, adj))
            return 0;

        // Count vertices with odd degree
        int odd = 0;
        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0)
                odd++;
        }

        // Determine Eulerian type
        if (odd == 0) return 2;       // Eulerian Circuit
        else if (odd == 2) return 1;  // Eulerian Path only
        else return 0;                // Not Eulerian
    }
};
