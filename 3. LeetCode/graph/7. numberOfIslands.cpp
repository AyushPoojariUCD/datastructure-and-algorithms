class Solution {
  private:
    // DFS
    void dfs(int row, int col, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Base case: out of bounds or water
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != 'L')
            return;

        // Mark current cell as visited (turn land into water)
        grid[row][col] = 'W';

        // 8 possible directions
        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int k = 0; k < 8; k++) {
            int nr = row + dr[k];
            int nc = col + dc[k];
            dfs(nr, nc, grid);
        }
    }

    // BFS
    void bfs(int r, int c, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        q.push({r, c});
        grid[r][c] = 'W';

        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int k = 0; k < 8; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 'L') {
                    grid[nr][nc] = 'W';
                    q.push({nr, nc});
                }
            }
        }
    }

  public:
    int countIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size(), n = grid[0].size();
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'L') {
                    islands++;
                    // dfs(i, j, grid);   
                    bfs(i, j, grid);
                }
            }
        }

        return islands;
    }
};
