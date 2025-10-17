#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Mark current cell as visited
        vis[row][col] = 1;
        int area = 1;

        // 8 possible directions
        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int k = 0; k < 8; k++) {
            int nr = row + dr[k];
            int nc = col + dc[k];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m && 
                !vis[nr][nc] && grid[nr][nc] == 1) {
                area += dfs(nr, nc, grid, vis);
            }
        }
        return area;
    }
    
    // BFS approach
    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        
        int area = 0;
        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            area++;

            for (int k = 0; k < 8; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m && 
                    !vis[nr][nc] && grid[nr][nc] == 1) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        
        return area;
    }

  public:
    // Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    // int area = dfs(i, j, grid, vis);
                    // maxArea = max(maxArea, area);
                    int area = bfs(i, j, grid, vis);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
