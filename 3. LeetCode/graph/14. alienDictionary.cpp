class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_set<char> uniqueChars;
        
        for (auto &w : words) {
            for (char c : w) uniqueChars.insert(c);
        }
        
        int K = uniqueChars.size();
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        
        for (char c : uniqueChars) indegree[c] = 0;
        
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.size(), w2.size());

            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2)
                return "";

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    break;  
                }
            }
        }
        
        queue<char> q;
        
        for (auto &it : indegree) {
            if (it.second == 0) q.push(it.first);
        }
        
        string order;
        
        while (!q.empty()) {
            char ch = q.front();
            q.pop();
            order += ch;

            for (char nei : adj[ch]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }
        
        if (order.size() < uniqueChars.size()) return ""; 
        
        return order;
    }
};