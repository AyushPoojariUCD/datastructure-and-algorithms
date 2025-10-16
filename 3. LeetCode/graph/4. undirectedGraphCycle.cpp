class Solution {
  private:
    bool dfs(int node,int parent,vector<int> adj[],vector<int> visited){
        visited[node] = 1;
        for(auto nei: adj[node]){
            if(!visited[nei]){
                if(dfs(nei,node,adj,visited)) return true;
            }
            else if(nei != parent){
                return true;
            }
        }
        return false;
    }
    
    bool bfs(int start, vector<int> adj[], vector<int>& visited) {
        queue<pair<int,int>> q;
        q.push({start, -1});
        visited[start] = 1;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto nei : adj[node]) {
                if (!visited[nei]) {
                    visited[nei] = 1;
                    q.push({nei, node});
                } 
                else if (nei != parent) {
                    return true;
                }
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V, 0);

        // BFS
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfs(i, adj, visited))
                    return true;
            }
        }

        // DFS
        // vector<int> visited(V,0);
        // for(int i = 0; i < V; i++){
        //     if(!visited[i])
        //         if(dfs(i,-1,adj,visited)) 
        //             return true;
        // }
        // return false;
        
        return false;
    }
};