class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < arr.size(); i++) {
            int diff = target - arr[i];
            if (map.find(diff) != map.end()) {
                return true;  
            }
            map[arr[i]] = i; 
        }
        return false; 
    }
};
