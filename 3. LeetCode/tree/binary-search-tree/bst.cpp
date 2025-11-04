#include <iostream>
using namespace std;

// Node structure for BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// BST class definition
class BST {
private:
    Node* insert(Node* root, int val) {
        if (!root) return new Node(val);

        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);

        return root;
    }

    Node* search(Node* root, int key) {
        if (!root || root->data == key)
            return root;

        if (key < root->data)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    Node* findMin(Node* root) {
        while (root && root->left)
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            // Node found — handle 3 cases
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                // Two children — replace with inorder successor
                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

public:
    Node* root;

    BST() { root = nullptr; }

    void insert(int val) {
        root = insert(root, val);
    }

    bool search(int key) {
        return search(root, key) != nullptr;
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }
};

// Driver code
int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "Preorder traversal: ";
    tree.preorder();

    cout << "Postorder traversal: ";
    tree.postorder();

    cout << "\nSearch 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Delete 20\n";
    tree.deleteNode(20);

    cout << "Inorder after deletion: ";
    tree.inorder();

    cout << "Delete 30\n";
    tree.deleteNode(30);
    cout << "Inorder after deletion: ";
    tree.inorder();

    cout << "Delete 50\n";
    tree.deleteNode(50);
    cout << "Inorder after deletion: ";
    tree.inorder();

    return 0;
}
