class Solution {
public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int left = 0, sum = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            // shrink from left if sum > target
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                // returning 1-based indices [left+1, right+1]
                return {left + 1, right + 1};
            }
        }
        return {-1}; // no subarray found
    }
};
