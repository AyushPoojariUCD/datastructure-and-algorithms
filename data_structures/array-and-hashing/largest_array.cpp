class Solution {
  public:
    int largest(vector<int> &arr) {
        int n = arr.size();
        int maxVal = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }
};
