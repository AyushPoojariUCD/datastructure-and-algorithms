class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        // 8 directions
        vector<pair<int,int>> dirs = {
            {1,0}, {-1,0}, {0,1}, {0,-1},
            {1,1}, {1,-1}, {-1,1}, {-1,-1}
        };

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1; // mark visited with distance (reuse grid)

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            int dist = grid[r][c];

            if (r == n-1 && c == n-1) return dist;

            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = dist + 1; // store distance
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};
