#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (!node->left) {
                node->left = newNode;
                return;
            } else q.push(node->left);

            if (!node->right) {
                node->right = newNode;
                return;
            } else q.push(node->right);
        }
    }

    Node* getRoot() { return root; }

    void findAllPaths(Node* root, vector<int>& path, vector<vector<int>> &allPaths) {
        if (!root) return;
        path.push_back(root->data);
        if (!root->left && !root->right) {
            allPaths.push_back(path);
        } else {
            findAllPaths(root->left,path,allPaths);
            findAllPaths(root->right,path,allPaths);
        }
        path.pop_back();
    }

    

    void paths() {
        vector<int> path;
        vector<vector<int>> allPaths;
        findAllPaths(root,path,allPaths);
        cout << "All Root-to-Leaf Paths:\n";
        for (auto& p : allPaths) {
            for (int val : p) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    BinaryTree tree;
    for (int i = 1; i <= 8; i++) tree.insert(i);
    tree.paths();
    return 0;
}
