class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        
        long long sumN = n * (n + 1) / 2;
        long long sumSqN = n * (n + 1) * (2 * n + 1) / 6;
        
        long long sum = 0, sumSq = 0;
        for(long long x : arr) {
            sum += x;
            sumSq += 1LL * x * x;
        }
        
        long long diff = sum - sumN;          // R - M
        long long sqDiff = sumSq - sumSqN;   // R^2 - M^2 = (R - M)(R + M)
        
        long long sumRM = sqDiff / diff;     // R + M
        
        long long R = (diff + sumRM) / 2;
        long long M = R - diff;
        
        return {(int)R, (int)M};
    }
};
