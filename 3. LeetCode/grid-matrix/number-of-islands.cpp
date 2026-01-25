#include<queue>
#include<vector>
#include<iostream>
using namespace std;


// Print Array
void printArray(vector<vector<string>>& grid){
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// DFS
void dfs(int row, int col, int m, int n, vector<vector<string>>& grid){
    if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == "0") return;
    grid[row][col] = "0";
    dfs(row + 1,col,m,n,grid);
    dfs(row - 1,col,m,n,grid);
    dfs(row,col + 1,m,n,grid);
    dfs(row,col - 1,m,n,grid);
}

// BFS
int bfs(int row, int col, int m, int n,vector<vector<string>> &grid){
    int numberOfIslands = 0;

    queue<pair<int,int>> q;
    q.push({row,col});

    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(auto d: dirs){
            int nr = r + d[0];
            int nc = c + d[1];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == "1"){
                numberOfIslands++;
                grid[nr][nc] = "0";
                q.push({nr,nc});
            }
        }
    }

    return numberOfIslands;
}


int numberOfIslands(vector<vector<string>>& grid) {
    if (grid.empty()) return 0;
    int numberOfIslands = 0;
    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == "1"){
                numberOfIslands++;
                bfs(i,j,m,n,grid);
                // dfs(i,j,m,n,grid);
            }
        }
    }
    return numberOfIslands;
} 

int main(){
    vector<vector<string>> grid = {
        {"1","1","1","1","0"},
        {"1","1","0","1","0"},
        {"1","1","0","0","0"},
        {"0","0","0","0","0"}
    };
    cout << "Grid:" << endl;
    printArray(grid);
    cout << "Number of Islands:" << numberOfIslands(grid);
    return 0;
}