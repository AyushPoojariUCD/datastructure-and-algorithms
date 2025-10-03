class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;              // already at end
        if (arr[0] == 0) return -1;        // cannot move
        
        int maxReach = arr[0];
        int steps = arr[0];
        int jumps = 1;
        
        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps;  // reached end
            
            maxReach = max(maxReach, i + arr[i]);
            steps--;
            
            if (steps == 0) {
                jumps++;
                if (i >= maxReach) return -1; // stuck, can’t move further
                steps = maxReach - i;
            }
        }
        return -1;
    }
};
