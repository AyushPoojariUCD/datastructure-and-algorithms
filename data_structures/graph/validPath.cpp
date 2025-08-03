#include <vector>
#include <queue>
#include <numeric>
using namespace std;

// ---------- DSU Class ----------
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    void Union(int x, int y) {
        int xp = find(x), yp = find(y);
        if (xp == yp) return;
        if (rank[xp] < rank[yp])
            parent[xp] = yp;
        else if (rank[xp] > rank[yp])
            parent[yp] = xp;
        else {
            parent[yp] = xp;
            rank[xp]++;
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

// ---------- Main Solution ----------
class Solution {
    // ----- DFS Helper -----
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int current, int end) {
        if (current == end) return true;
        if (visited[current]) return false;
        visited[current] = true;
        for (int neighbor : graph[current]) {
            if (dfs(graph, visited, neighbor, end))
                return true;
        }
        return false;
    }

    // ----- Build Graph -----
    vector<vector<int>> buildGraph(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        // === Uncomment the desired approach ===

        // --- Approach 1: Union Find (DSU) ---
        /*
        DSU uf(n);
        for (const auto& edge : edges)
            uf.Union(edge[0], edge[1]);
        return uf.isConnected(start, end);
        */

        // --- Approach 2: BFS ---
        /*
        vector<vector<int>> graph = buildGraph(n, edges);
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            if (curr == end) return true;
            for (int neighbor : graph[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
        */

        // --- Approach 3: DFS ---
        vector<vector<int>> graph = buildGraph(n, edges);
        vector<bool> visited(n, false);
        return dfs(graph, visited, start, end);
    }
};
