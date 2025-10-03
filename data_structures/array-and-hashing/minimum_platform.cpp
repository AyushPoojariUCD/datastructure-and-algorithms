class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0, j = 0;
        int platforms = 0, maxPlatforms = 0;
        
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                // new train arrives before previous departs
                platforms++;
                maxPlatforms = max(maxPlatforms, platforms);
                i++;
            } else {
                // a train departs → free platform
                platforms--;
                j++;
            }
        }
        
        return maxPlatforms;
    }
};
