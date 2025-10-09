class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int maxSum = arr[0];
        int currSum = arr[0];
        for(int i = 1; i < arr.size(); i++){
            currSum = max(arr[i],arr[i] + currSum);
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};