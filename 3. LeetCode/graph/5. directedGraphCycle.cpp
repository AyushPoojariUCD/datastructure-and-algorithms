class Solution {
  private:
    // Kahn Algorithm : Topological Sort
    bool kahn(int V, vector<vector<int>> &edges){
        
        vector<vector<int>> adj(V);
        
        vector<int> indegree(V,0);

        for(auto e: edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int count = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto nei: adj[node]){
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }
        
        return (count != V);
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        return kahn(V,edges);
    }
};