class Solution {
  public:
    // Utility DFS function
    void dfs(int u, vector<int> adj[], vector<bool>& visited) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) dfs(v, adj, visited);
        }
    }

    bool isConnected(int v, vector<int> adj[]) {
        vector<bool> visited(v, false);

        // Find a vertex with non-zero degree
        int start = -1;
        for (int i = 0; i < v; i++) {
            if (!adj[i].empty()) {
                start = i;
                break;
            }
        }

        // If all vertices have zero degree, graph is trivially Eulerian
        if (start == -1) return true;

        // DFS from first non-isolated vertex
        dfs(start, adj, visited);

        // Check if all non-zero degree vertices are visited
        for (int i = 0; i < v; i++) {
            if (!adj[i].empty() && !visited[i])
                return false;
        }

        return true;
    }

    bool isEularCircuitExist(int v, vector<int> adj[]) {
        // 1. Check if graph is connected
        if (!isConnected(v, adj)) return false;

        // 2. Check if all vertices have even degree
        for (int i = 0; i < v; i++) {
            if (adj[i].size() % 2 != 0)
                return false;
        }

        return true;  // All vertices have even degree and graph is connected
    }
};
