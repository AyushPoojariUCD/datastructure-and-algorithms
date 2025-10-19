// User function template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) {
        unordered_map<string, int> freq;
        unordered_map<string, int> firstIdx;

        int maxFreq = 0;
        for (int i = 0; i < n; ++i) {
            const string &w = arr[i];
            if (!firstIdx.count(w)) firstIdx[w] = i;  // record first occurrence
            maxFreq = max(maxFreq, ++freq[w]);
        }

        // Among words with maxFreq, pick the one whose FIRST occurrence is latest
        string ans;
        int bestFirst = -1;
        for (auto &kv : freq) {
            const string &w = kv.first;
            if (kv.second == maxFreq) {
                int fi = firstIdx[w];
                if (fi > bestFirst) {
                    bestFirst = fi;
                    ans = w;
                }
            }
        }
        return ans;
    }
};
