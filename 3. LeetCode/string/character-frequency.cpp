#include <bits/stdc++.h>
using namespace std;

// Find duplicate characters
void findDuplicate(string &s){
    vector<string> ans;
    unordered_map<char,int> freq;
    for(auto ch: s){
        freq[ch]++;
    }
    for(auto it: freq){
        cout << it.first << " " << it.second << "\n";
    }
}

/* Main Function */
int main() {
    string s = "abcdeabcdabcaba";
    findDuplicate(s);
    return 0;
}
