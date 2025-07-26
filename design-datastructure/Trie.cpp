#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;

        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; ++i)
                children[i] = nullptr;
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEndOfWord = true;
    }

    // Search for a full word
    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return node->isEndOfWord;
    }

    // Check if any word starts with the given prefix
    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return true;
    }
};


int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");

    cout << trie.search("app") << endl;       // true
    cout << trie.search("apple") << endl;     // true
    cout << trie.search("apples") << endl;    // false
    cout << trie.startsWith("ap") << endl;    // true
    cout << trie.startsWith("ba") << endl;    // false
}
