#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int n, m;
    vector<int> dr = {-1,-1,-1,0,0,1,1,1};
    vector<int> dc = {-1,0,1,-1,1,-1,0,1};

    bool dfs(int r, int c, vector<vector<char>>& board,
             string& word, int index, vector<vector<int>>& visited) {
        if (index == word.size()) return true; // all chars matched
        
        if (r < 0 || r >= n || c < 0 || c >= m) return false;
        if (visited[r][c] || board[r][c] != word[index]) return false;

        visited[r][c] = 1;

        // explore all 8 directions
        for (int k = 0; k < 8; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (dfs(nr, nc, board, word, index + 1, visited)) {
                visited[r][c] = 0; // backtrack before returning
                return true;
            }
        }

        visited[r][c] = 0; // backtrack
        return false;
    }

    bool exists(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, board, word, 0, visited))
                        return true;
                }
            }
        }
        return false;
    }

  public:
    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        set<string> result; // use set to avoid duplicates
        for (auto& word : dictionary) {
            if (exists(board, word))
                result.insert(word);
        }

        return vector<string>(result.begin(), result.end());
    }
};
