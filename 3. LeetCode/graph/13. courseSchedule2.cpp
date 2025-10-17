class Solution {
private:
    // DFS Algorithm Time: O(V + E)  Space: O(V + E)
    // Order in Postorder Traversal
    
    // DFS Helper
    bool dfsRec(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& order) {
        // currently visiting
        vis[node] = 1;  
        
        for (int next : adj[node]) {
            if (vis[next] == 0) {
                // Found a cycle
                if (dfsRec(next, adj, vis, order)) 
                    return true;  
            } 
            // Back edge -> cycle
            else if (vis[next] == 1) {
                return true;  
            }
        }
        // Done visiting
        vis[node] = 2;  
        order.push_back(node);
        return false;
    }

    // DFS Topological Sort
    vector<int> dfs(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
        }

        vector<int> vis(numCourses, 0);
        vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfsRec(i, adj, vis, order)) 
                    // cycle found -> invalid order
                    return {};  
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }

    // Kahn’s Algorithm Time: O(V + E)  Space: O(V + E)
    vector<int> kahn(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topo;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            topo.push_back(curr);
            for (int next : adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }

        if ((int)topo.size() == numCourses) return topo;

        return {};
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) { 
        return dfs(numCourses, prerequisites);
        // return kahn(numCourses, prerequisites);
    }
};
