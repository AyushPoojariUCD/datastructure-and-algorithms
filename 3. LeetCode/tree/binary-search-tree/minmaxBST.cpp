#include<bits/stdc++.h>
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

	Node* insertHelper(Node* root, int val) {
        if (!root) return new Node(val);
        if (val < root->data) root->left = insertHelper(root->left, val);
        else if (val > root->data) root->right = insertHelper(root->right, val);
        return root;
    }
    
    int minValue(Node* root) {
        if(!root) return -1;
        while(root->left != nullptr){
            root = root->left;
        }
        return root->data;
    }
    
    int maxValue(Node* root){
        if(!root) return -1;
        while(root->right){
            root = root->right;
        }
        return root->data;
    }
    
    int getMaximum(){
        return maxValue(root);    
    }
    
    int getMinimum(){
        return minValue(root);
    }
    
    void insert(int val) {
        root = insertHelper(root, val);
    }
};

/*
    Example: Tree
    
            [10]    - 0
            / \
        [20] [30]   - 1
        / \
    [40] [50]       - 2
*/
int main() {
	BinaryTree tree;
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);
	tree.insert(60);
	cout << "Minimum Value: " << tree.getMinimum();
	cout << endl;
	cout << "Maximum Value: " << tree.getMaximum();
	return 0;
}