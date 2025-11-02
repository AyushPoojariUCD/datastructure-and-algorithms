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
            Node* temp = q.front();
            q.pop();
            if (!temp->left) {
                temp->left = newNode;
                return;
            } else q.push(temp->left);
            if (!temp->right) {
                temp->right = newNode;
                return;
            } else q.push(temp->right);
        }
    }

    Node* getRoot() { return root; }

    int height(Node* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int countLeafNodes(Node* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }

    int countInternalNodes(Node* root) {
        if (!root || (!root->left && !root->right)) return 0;
        return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
    }

    int diameterUtil(Node* root, int& diameter) {
        if (!root) return 0;
        int lh = diameterUtil(root->left, diameter);
        int rh = diameterUtil(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }

    int diameter(Node* root) {
        int dia = 0;
        diameterUtil(root, dia);
        return dia;
    }

    int checkBalance(Node* root) {
        if (!root) return 0;
        int lh = checkBalance(root->left);
        if (lh == -1) return -1;
        int rh = checkBalance(root->right);
        if (rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;
        return 1 + max(lh, rh);
    }

    bool isBalanced(Node* root) {
        return checkBalance(root) != -1;
    }

    bool isIdentical(Node* r1, Node* r2) {
        if (!r1 && !r2) return true;
        if (!r1 || !r2) return false;
        return (r1->data == r2->data) &&
               isIdentical(r1->left, r2->left) &&
               isIdentical(r1->right, r2->right);
    }

    bool isMirror(Node* a, Node* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return (a->data == b->data) &&
               isMirror(a->left, b->right) &&
               isMirror(a->right, b->left);
    }

    bool isSymmetric(Node* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

    int maxWidth(Node* root) {
        if (!root) return 0;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            int minIndex = q.front().second;
            int first, last;
            for (int i = 0; i < size; i++) {
                auto it = q.front(); q.pop();
                int currIndex = it.second - minIndex;
                Node* node = it.first;
                if (i == 0) first = currIndex;
                if (i == size - 1) last = currIndex;
                if (node->left) q.push({node->left, currIndex * 2 + 1});
                if (node->right) q.push({node->right, currIndex * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }

    void convertToMirror(Node* root) {
        if (!root) return;
        swap(root->left, root->right);
        convertToMirror(root->left);
        convertToMirror(root->right);
    }

    void structuralInfo() {
        cout << "Height: " << height(root) << endl;
        cout << "Diameter: " << diameter(root) << endl;
        cout << "Total Nodes: " << countNodes(root) << endl;
        cout << "Leaf Nodes: " << countLeafNodes(root) << endl;
        cout << "Internal Nodes: " << countInternalNodes(root) << endl;
        cout << "Is Balanced: " << (isBalanced(root) ? "Yes" : "No") << endl;
        cout << "Is Symmetric: " << (isSymmetric(root) ? "Yes" : "No") << endl;
        cout << "Max Width: " << maxWidth(root) << endl;

        convertToMirror(root);
        cout << "Tree converted to Mirror successfully." << endl;
    }
};


int main() {
    BinaryTree tree;
    for (int i = 1; i <= 7; i++) tree.insert(i);
    tree.structuralInfo();

    BinaryTree tree2;
    for (int i = 1; i <= 7; i++) tree2.insert(i);
    cout << "Is Identical: " << (tree.isIdentical(tree.getRoot(), tree2.getRoot()) ? "Yes" : "No") << endl;
    return 0;
}
