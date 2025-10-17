class Solution {
private:
    // DFS Algorithm Time: O(V + E)  Space: O(V + E)
    // DFS -> Time: O(V+E)
    bool dfsRec(int node, vector<vector<int>>& adj, vector<int>& vis) {
        // Currently visiting
        vis[node] = 1;  
        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                if (dfsRec(it, adj, vis)) return true;
            } 
            else if (vis[it] == 1) {
                // Found a back edge → cycle
                return true;
            }
        }
        // Fully processed
        vis[node] = 2;  
        return false;
    }
    
    bool dfs(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> adj(numCourses);

        for (auto& e : prerequisites) {
            int u = e[0], v = e[1];
            adj[v].push_back(u);
        }

        vector<int> vis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfsRec(i, adj, vis))
                    return false;  // found cycle
            }
        }
        // no cycle → all courses can be finished
        return true;  
    }

    // Topological Sort => Kahn’s Algorithm Time: O(V + E)  Space: O(V + E)
    bool kahn(int numCourses,vector<vector<int>>& prerequisites) {
        int taken = 0;

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
            taken++;
            for (int next : adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }

        return taken == numCourses;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // return dfs(numCourses, prerequisites);
        return kahn(numCourses, prerequisites);
    }
};