class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size();
        
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nei: adj[node]){
                if(dist[nei] + 1 < dist[node]){
                    dist[nei] = dist[node] + 1;
                    q.push(nei);
                }
            }
        }
        
        for(int i = 0; i < V; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};