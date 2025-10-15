class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        const int INF = 1e9;
        
        vector<int> distance(V,INF);
        
        distance[src] = 0;
        
        for(int i = 0; i < V - 1; i++){
            for (auto &e : edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];

                if (distance[u] != INF && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                }
            }
        }
        
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (distance[u] != INF && distance[u] + w < distance[v]) {
                return {-1};
            }
        }
        
        return distance;
    }
};
