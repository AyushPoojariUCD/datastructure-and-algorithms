class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;

        // Build graph
        for (auto& p : pairs) {
            adj[p[0]].push_back(p[1]);
            outdegree[p[0]]++;
            indegree[p[1]]++;
        }

        // Find the start node
        int start = pairs[0][0];
        for (auto& [node, _] : adj) {
            if (outdegree[node] - indegree[node] == 1) {
                start = node;
                break;
            }
        }

        // Iterative Hierholzer's algorithm
        vector<vector<int>> result;
        stack<int> stk;
        stk.push(start);

        while (!stk.empty()) {
            int u = stk.top();
            if (!adj[u].empty()) {
                int v = adj[u].back();
                adj[u].pop_back();
                stk.push(v);
            } else {
                stk.pop();
                if (!stk.empty()) {
                    result.push_back({stk.top(), u});
                }
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};