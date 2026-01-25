#include<queue>
#include<vector>
#include<iostream>
using namespace std;

int dfs(int row, int col, int m, int n, vector<vector<int>>& grid){
    if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0) return 0;
    grid[row][col] = 0;
    int area = 1;
    area += dfs(row + 1,col,m,n,grid);
    area += dfs(row - 1,col,m,n,grid);
    area += dfs(row,col + 1,m,n,grid);
    area += dfs(row,col - 1,m,n,grid);
    return area;
}

int bfs(int row, int col, int m, int n, vector<vector<int>>& grid){
    int area = 1;

    queue<pair<int,int>> q;
    q.push({row,col});

    grid[row][col] = 0;

    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(auto d: dirs){
            int nr = r + d[0];
            int nc = c + d[1];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1){
                grid[nr][nc] = 0;
                area++;
                q.push({nr,nc});
            }
        }
    }

    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int area = 0;
    int maxArea = 0;
    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                area = bfs(i,j,m,n,grid);
                maxArea = max(maxArea,area);
            }
        }
    }
    return maxArea;
}

int main(){
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout << "Maximum Area of Island:" <<  maxAreaOfIsland(grid);
    return 0;
}
