class Solution {
public:
    // Trie Datastructure Approach -> Time: O(n*m)  Space: O(n*m)
    // Suitable for computing mutiple lcp
    struct TrieNode {
        bool isEnd;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isEnd(false) {}
    };

    string longestCommonPrefixTrie(vector<string>& strs) {
        if (strs.empty())
            return "";
        // Build Trie
        TrieNode* root = new TrieNode();
        for (auto& word : strs) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children.count(c)) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->isEnd = true;
        }
        // Find prefix
        string prefix = "";
        TrieNode* node = root;
        while (node && node->children.size() == 1 && !node->isEnd) {
            auto it = node->children.begin();
            prefix += it->first;
            node = it->second;
        }
        return prefix;
    }

    // Iterative Shrinking Approach -> Time: O(n*m)  Space: O(m)
    // Suitable for computing less lcp
    string longestCommonPrefixIterative(vector<string>& strs) {
        if (strs.empty())
            return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() &&
                   prefix[j] == strs[i][j]) {
                j++;
            }
            prefix = prefix.substr(0, j);
            if (prefix.empty())
                return "";
        }
        return prefix;
    }

    string longestCommonPrefix(vector<string>& strs) {
        return longestCommonPrefixIterative(strs);
    }
};
