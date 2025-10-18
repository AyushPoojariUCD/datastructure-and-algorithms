class Solution {
  public:
    void dfs(int u, vector<int> adj[], vector<int>& disc, vector<int>& low,
         stack<int>& st, vector<bool>& inStack, int& timer, vector<vector<int>>& sccs) {

    disc[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            dfs(v, adj, disc, low, st, inStack, timer, sccs);
            low[u] = min(low[u], low[v]);
        } 
        else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    // Root node of SCC
    if (low[u] == disc[u]) {
        vector<int> scc;
        while (true) {
            int node = st.top(); st.pop();
            inStack[node] = false;
            scc.push_back(node);
            if (node == u) break;
        }
        sort(scc.begin(), scc.end());
        sccs.push_back(scc);
    }
}

vector<vector<int>> tarjans(int V, vector<int> adj[]) {
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> inStack(V, false);
    stack<int> st;
    vector<vector<int>> sccs;
    int timer = 0;

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1)
            dfs(i, adj, disc, low, st, inStack, timer, sccs);
    }

    sort(sccs.begin(), sccs.end());
    return sccs;
}

};