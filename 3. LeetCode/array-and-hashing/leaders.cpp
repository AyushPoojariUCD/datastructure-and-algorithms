class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        
        int maxSoFar = arr[n-1];           // last element is always a leader
        result.push_back(maxSoFar);
        
        // Traverse from right to left
        for (int i = n-2; i >= 0; i--) {
            if (arr[i] >= maxSoFar) {
                maxSoFar = arr[i];
                result.push_back(arr[i]);
            }
        }
        
        // reverse to maintain left-to-right order
        reverse(result.begin(), result.end());
        return result;
    }
};
