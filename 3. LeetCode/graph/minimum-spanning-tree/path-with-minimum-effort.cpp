class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // directions: up, down, left, right
        vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        // min effort to reach each cell
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        effort[0][0] = 0;

        // min-heap: {effort, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int e = curr[0];
            int x = curr[1];
            int y = curr[2];
            // destination reached
            if (x == m-1 && y == n-1) return e;
            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                int newEffort = max(e, abs(heights[nx][ny] - heights[x][y]));
                if (newEffort < effort[nx][ny]) {
                    effort[nx][ny] = newEffort;
                    pq.push({newEffort, nx, ny});
                }
            }
        }
        // should never reach here
        return 0;
    }
};
