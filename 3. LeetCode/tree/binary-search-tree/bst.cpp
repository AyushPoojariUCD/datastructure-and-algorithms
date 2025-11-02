#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Binary Search Tree class
class BST {
private:
    Node* root;

    // Insertion
    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    // Search
    bool search(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

    // Find Minimum
    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // Deletion
    Node* remove(Node* node, int val) {
        if (!node) return nullptr;

        if (val < node->data)
            node->left = remove(node->left, val);
        else if (val > node->data)
            node->right = remove(node->right, val);
        else {
            // Case 1 & 2: node with 0 or 1 child
            if (!node->left)
                return node->right;
            else if (!node->right)
                return node->left;

            // Case 3: node with 2 children
            Node* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = remove(node->right, minNode->data);
        }
        return node;
    }

    // Inorder traversal
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Preorder traversal
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Postorder traversal
    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BST() {
        root = nullptr; 
        
    }

    void insert(int val) { 
        root = insert(root, val); 
    }
    
    bool search(int val) { 
        return search(root, val); 
    }
    
    void remove(int val) { 
        root = remove(root, val); 
    }

    void traversal() {
        cout << "Inorder Traversal: ";
        inorder(root); 
        cout << endl;
        
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl; 
        
        cout << "Postorder Traversal: ";
        postorder(root); 
        cout << endl; 
    }

    int findMin() {
        Node* minNode = findMin(root);
        if (minNode) return minNode->data;
        throw runtime_error("Tree is empty");
    }

    int findMax() {
        Node* node = root;
        if (!node) throw runtime_error("Tree is empty");
        while (node->right)
            node = node->right;
        return node->data;
    }
    
    bool checkBst(Node* node, long long minVal, long long maxVal){
        if(!node) return true;
        if(node->data <= minVal || node->data >= maxVal)
            return false;
        return checkBst(node->left,minVal,node->data) &&
               checkBst(node->right, node->data, maxVal);
    }
    
    bool isBST() {
        return checkBst(root,LLONG_MIN,LLONG_MAX);
    }
    
    int height(Node* node){
        if(!node) return 0;
        int lh = height(node->left);
        if(lh == -1) return -1;
        int rh = height(node->right);
        if(rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }
    
    bool isBalanced(Node* root) {
        return height(root) != -1;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.traversal();
    cout << "Min value: " << tree.findMin() << endl;
    cout << "Max value: " << tree.findMax() << endl;
    cout << "Searching 60: " << (tree.search(60) ? "Found" : "Not Found") << endl;
    cout << "Deleting 20...\n";
    tree.remove(20);
    cout << "Check BST: " << tree.isBST();
    return 0;
}
