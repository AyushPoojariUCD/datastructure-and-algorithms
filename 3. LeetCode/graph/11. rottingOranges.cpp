class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int minutes, int m,
             int n) {
        // Out of bounds or not fresh or already better time
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;
        if (grid[r][c] != 1 && grid[r][c] < minutes)
            return;
        grid[r][c] = minutes;
        // Spread rot recursively to 4 directions
        dfs(grid, r + 1, c, minutes + 1, m, n);
        dfs(grid, r - 1, c, minutes + 1, m, n);
        dfs(grid, r, c + 1, minutes + 1, m, n);
        dfs(grid, r, c - 1, minutes + 1, m, n);
    }

    int bfs(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Push all initially rotten oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i,j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        
        // No fresh oranges
        if (fresh == 0) return 0; 
        int minutes = -1;
        vector<int> dirs = {0,1,0,-1,0};
        
        // Step 2: BFS - multi-source level order traversal
        while (!q.empty()) {
            int sz = q.size();
            minutes++;
            while (sz--) {
                auto [r,c] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int nr = r + dirs[k], nc = c + dirs[k+1];
                    if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return (fresh == 0) ? minutes : -1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
        // int m = grid.size();
        // int n = grid[0].size();
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         // start time = 2 (to distinguish from empty/fresh)
        //         if (grid[i][j] == 2)
        //             dfs(grid, i, j, 2, m,n); 
        //     }
        // }
        // int minutes = 2; 
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (grid[i][j] == 1)
        //             return -1;
        //         minutes = max(minutes, grid[i][j]);
        //     }
        // }
        // return minutes - 2;
    }
};
