class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
            return;
        
        grid[r][c] = 0; 
        
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    void bfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0; 

        vector<int> dirs = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k];
                int ny = y + dirs[k + 1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
    }

    int numberOfEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Step 1: Eliminate all lands connected to boundaries
        for (int i = 0; i < m; i++) {
            // dfs(grid, i, 0);                                 // left border
            // dfs(grid, i, n - 1);                             // right border
            if (grid[i][0] == 1) bfs(grid, i, 0);               // left boundary
            if (grid[i][n - 1] == 1) bfs(grid, i, n - 1);       // right boundary
        }
        
        for (int j = 0; j < n; j++) {
            // dfs(grid, 0, j);                                 // top border
            // dfs(grid, m - 1, j);                             // bottom border
            if (grid[0][j] == 1) bfs(grid, 0, j);               // top boundary
            if (grid[m - 1][j] == 1) bfs(grid, m - 1, j);       // bottom boundary
        }
        
        // Step 2: Count remaining land cells
        int enclaves = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    enclaves++;
            }
        }
        
        return enclaves;
    }
};
