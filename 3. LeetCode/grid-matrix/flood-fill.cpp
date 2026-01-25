#include<queue>
#include<vector>
#include<iostream>
using namespace std;

// DFS
void dfs(int row, int col, int m, int n, int originalColor, int color, vector<vector<int>>& image){
    if(row < 0 || col < 0 || row >= m || col >= n) return;
    if(image[row][col] != originalColor) return;
    image[row][col] = color;
    dfs(row + 1,col,m,n,originalColor,color,image);
    dfs(row - 1,col,m,n,originalColor,color,image); 
    dfs(row,col + 1,m,n,originalColor,color,image); 
    dfs(row,col - 1,m,n,originalColor,color,image); 
}

// BFS
vector<vector<int>> bfs(vector<vector<int>>& image, int sr, int sc, int color){
    int m = image.size();
        int n = image[0].size();
        
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});

        image[sr][sc] = color;

        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto &d: dirs){
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && 
                    image[nr][nc] == originalColor){
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
        }
    return image;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size();
    int n = image[0].size();
    int originalColor = image[sr][sc];
    if(originalColor == color) return image;
    bfs(image,sr,sc,color);
    return image;
} 

int main(){
    vector<vector<int>> image = {
    {1, 1, 1},
    {1, 1, 0},
    {1, 0, 1}
    };
    int color = 2;
    int sr = 1, sc = 1;
    floodFill(image,sr,sc,color);
    for(int i = 0; i < image.size(); i++){
        for(int j = 0; j < image[0].size(); j++){
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}