class Solution {
  private:
    void dfs(int node, vector<vector<int>> adj, vector<int> &visited){
        visited[node] = 1;
        for (int j = 0; j < adj.size(); j++) {
            if (adj[node][j] == 1 && !visited[j]) {
                dfs(j, adj, visited);
            }
        }
    }

    int bfs(vector<vector<int>> adj, int V) {
        vector<int> visited(V, 0);
        
        int provinces = 0;

        // Traverse all nodes
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                provinces++;

                // Start BFS from node i
                queue<int> q;
                q.push(i);
                visited[i] = 1;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    // Explore all adjacent nodes
                    for (int j = 0; j < V; j++) {
                        if (adj[node][j] == 1 && !visited[j]) {
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return provinces;
    }

 public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int provinces = 0;
        vector<int> visited(V,0);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                provinces++;
                dfs(i,adj,visited);
            }
        }
        return provinces;
    }
};