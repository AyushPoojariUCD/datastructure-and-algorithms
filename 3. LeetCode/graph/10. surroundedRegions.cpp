class Solution {
private:
    // Depth First Search Time: O(m×n)  Space: O(m×n)
    void dfs(int row,int col,vector<vector<char>>& board){
        int m = board.size(), n = board[0].size();
        if(row < 0 || row >= m || col < 0 || col >= n ||  board[row][col] != 'O') return;
        board[row][col] = '$';
        dfs(row + 1,col,board);
        dfs(row - 1,col,board);
        dfs(row,col + 1,board);
        dfs(row,col - 1,board);
    }

    // Breadth First Search: Time: O(m×n)   Space: O(m×n)
    void bfs(vector<vector<char>>& board, int r, int c) {
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        board[r][c] = '$';

        vector<int> dirs = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k];
                int ny = y + dirs[k + 1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                    board[nx][ny] == 'O') {
                    board[nx][ny] = '$';
                    q.push({nx, ny});
                }
            }
        }
    }
    
public:
    vector<vector<char>> fill(vector<vector<char>>& board) {
        if (board.empty())
            return {};

        int m = board.size();

        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                bfs(board, i, 0);
            if (board[i][n - 1] == 'O')
                bfs(board, i, n - 1);
            // dfs(i,0,board);
            // dfs(i,n-1,board);
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                bfs(board, 0, j);
            if (board[m - 1][j] == 'O')
                bfs(board, m - 1, j);
            // dfs(0,j,board);
            // dfs(m - 1,j,board);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '$')
                    board[i][j] = 'O';
            }
        }
        
        return board;
    }
};