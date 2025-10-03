class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        vector<int> temp(n);
        long long inv = mergeSortCount(arr, temp, 0, n - 1);
        // If you expect very large counts, change return type to long long.
        return (int)inv;
    }

  private:
    long long mergeSortCount(vector<int>& a, vector<int>& temp, int l, int r) {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;
        long long inv = 0;
        inv += mergeSortCount(a, temp, l, m);
        inv += mergeSortCount(a, temp, m + 1, r);
        inv += merge(a, temp, l, m, r);
        return inv;
    }

    long long merge(vector<int>& a, vector<int>& temp, int l, int m, int r) {
        int i = l;       // pointer for left half
        int j = m + 1;   // pointer for right half
        int k = l;       // pointer for temp
        long long inv = 0;

        while (i <= m && j <= r) {
            if (a[i] <= a[j]) {
                temp[k++] = a[i++];
            } else {
                // a[i] > a[j], so (m - i + 1) inversions
                temp[k++] = a[j++];
                inv += (long long)(m - i + 1);
            }
        }
        // copy remaining
        while (i <= m) temp[k++] = a[i++];
        while (j <= r) temp[k++] = a[j++];

        // copy back to original array
        for (int idx = l; idx <= r; ++idx) a[idx] = temp[idx];

        return inv;
    }
};
