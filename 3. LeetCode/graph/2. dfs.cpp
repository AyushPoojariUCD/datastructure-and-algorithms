class Solution {
  private:
    void dfsRec(int node,vector<vector<int>>& adj,vector<int> &visited){
        visited[node] = 1;
        ans.push_back(node);
        for(auto nei: adj[node]){
            if(!visited[nei]){
                dfsRec(nei,adj,visited);
            }
        }
    }
  public:
    vector<int> ans;
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> visited(V,0);
        for(int i = 0; i < V; i++){
            if(!visited[i])
                dfsRec(i,adj,visited);
        }
        return ans;
    }
};