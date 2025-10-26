class Solution {
private:
    int linearSearch(vector<int>& nums, int target){
       int n = nums.size();
       for(int i = 0; i < n; i++){
            if(nums[i] == target) return i;
       } 
       return -1;
    }

    int binarySearchRec(vector<int>& nums, int low, int high, int target){
        if(low > high) return -1;
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) return mid;
        else if(target < nums[mid]){
            return binarySearchRec(nums, 0, mid - 1, target);
        }
        else{
            return binarySearchRec(nums, mid + 1, high, target);
        }
    }

    int binarySearch(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            else if(target < nums[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return -1;
    }

    int lowerBoundIndex(vector<int> &nums, int target){
        int low = 0;
        int ans = nums.size();
        int high = nums.size() - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }

    int higherBoundIndex(vector<int> &nums, int target){
        int low = 0;
        int ans = nums.size();
        int high = nums.size() - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }

    int lowerBound(vector<int>& nums, int target){
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return (it != nums.end() && *it == target) ? it - nums.begin() : -1;
    }

    int upperBound(vector<int>& nums, int target){
        auto it = upper_bound(nums.begin(), nums.end(), target);
        return (it != nums.begin() && *(--it) == target) ? it - nums.begin() : -1;
    }

public:
    int search(vector<int>& nums, int target) {
        // return linearSearch(nums, target);
        // return binarySearchRec(nums, 0, nums.size(), target);
        // return lowerBound(nums, target);
        // return upperBound(nums, target);
        return binarySearch(nums, target);
    }
};