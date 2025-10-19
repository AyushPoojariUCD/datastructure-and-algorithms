#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // Search for a word in the trie
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    // Check if any word starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return true;
    }

    // Delete a word from the trie
    bool deleteWord(string word) {
        return deleteHelper(root, word, 0);
    }

private:
    bool deleteHelper(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        // If at end of the word
        if (depth == word.size()) {
            if (!node->isEndOfWord)
                return false; // word not found
            node->isEndOfWord = false;

            // If node has no children, it can be deleted
            for (int i = 0; i < 26; i++)
                if (node->children[i])
                    return false;
            return true;
        }

        int index = word[depth] - 'a';
        if (deleteHelper(node->children[index], word, depth + 1)) {
            delete node->children[index];
            node->children[index] = nullptr;

            // Check if current node can also be deleted
            if (!node->isEndOfWord) {
                for (int i = 0; i < 26; i++)
                    if (node->children[i])
                        return false;
                return true;
            }
        }
        return false;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    cout << boolalpha;
    cout << "Search apple: " << trie.search("apple") << endl;   // true
    cout << "Search app: " << trie.search("app") << endl;       // true
    cout << "Search bat: " << trie.search("bat") << endl;       // true
    cout << "Search bad: " << trie.search("bad") << endl;       // false
    cout << "Prefix ap: " << trie.startsWith("ap") << endl;     // true

    trie.deleteWord("app");
    cout << "After deleting 'app', search app: " << trie.search("app") << endl; // false
    cout << "Search apple still exists: " << trie.search("apple") << endl;      // true
}
