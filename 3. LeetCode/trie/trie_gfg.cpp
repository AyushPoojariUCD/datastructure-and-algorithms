// User function template for C++
class Trie {
    struct Node {
        Node* links[26];   // pointers to next nodes
        bool isEnd;        // marks end of a word

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                links[i] = nullptr;
        }

        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }
    };

    Node* root;

  public:
    Trie() {
        root = new Node();
    }

    // Insert a word into the Trie
    void insert(string &word) {
        Node* node = root;
        for (char c : word) {
            if (!node->containsKey(c)) {
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        node->isEnd = true;
    }

    // Search a complete word in the Trie
    bool search(string &word) {
        Node* node = root;
        for (char c : word) {
            if (!node->containsKey(c))
                return false;
            node = node->get(c);
        }
        return node->isEnd;
    }

    // Check if a prefix exists in the Trie
    bool isPrefix(string &word) {
        Node* node = root;
        for (char c : word) {
            if (!node->containsKey(c))
                return false;
            node = node->get(c);
        }
        return true;
    }
};
