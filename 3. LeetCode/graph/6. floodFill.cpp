class Solution {
  private:
    void dfs(vector<vector<int>>& image, int r, int c, int newColor, int originalColor){
        int m = image.size();
        int n = image[0].size();
    
        if(r < 0 || r >= m || c < 0 || c >= n || image[r][c] != originalColor) return;
        
        image[r][c] = newColor;
    
        dfs(image,r + 1,c,newColor,originalColor);
        dfs(image,r - 1,c,newColor,originalColor);
        dfs(image,r,c + 1,newColor,originalColor);
        dfs(image,r,c - 1,newColor,originalColor);
    }
    
    vector<vector<int>> bfs(vector<vector<int>>& image, int sr, int sc, int newColor){
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];
        
        if (originalColor == newColor) return image;

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto [r, c] = q.front(); q.pop();
            for (auto &d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == originalColor) {
                    image[nr][nc] = newColor;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
    
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        
        // int originalColor = image[sr][sc];
        
        // if(originalColor == newColor) return image;
        
        // dfs(image,sr,sc,newColor,originalColor);
        
        // return image;
        
        return bfs(image,sr,sc,newColor);
    }
};