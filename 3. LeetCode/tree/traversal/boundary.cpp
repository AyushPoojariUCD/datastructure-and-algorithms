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

	void insert(int val) {
		Node* newNode = new Node(val);

		if(!root) {
			root = newNode;
			return;
		}

		queue<Node*> q;
		q.push(root);

		while(!q.empty()) {
			Node* node = q.front();
			q.pop();
			if(!node->left) {
				node->left = newNode;
				return;
			} else {
				q.push(node->left);
			}
			if(!node->right) {
				node->right = newNode;
				return;
			} else {
				q.push(node->right);
			}
		}
	}

	bool isLeaf(Node* node) {
		return !node->left && !node->right;
	}

	void addLeftBoundary(Node* root, vector<int>& res) {
		Node* curr = root->left;
		while (curr) {
			if (!isLeaf(curr)) res.push_back(curr->data);
			if (curr->left) curr = curr->left;
			else curr = curr->right;
		}
	}

	void addLeaves(Node* root, vector<int>& res) {
		if (isLeaf(root)) {
			res.push_back(root->data);
			return;
		}
		if (root->left) addLeaves(root->left, res);
		if (root->right) addLeaves(root->right, res);
	}

	void addRightBoundary(Node* root, vector<int>& res) {
		vector<int> temp;
		Node* curr = root->right;
		while (curr) {
			if (!isLeaf(curr)) temp.push_back(curr->data);
			if (curr->right) curr = curr->right;
			else curr = curr->left;
		}
		for (int i = temp.size() - 1; i >= 0; i--)
			res.push_back(temp[i]);
	}

	void boundaryTraversal(Node* root) {
		if (!root) return;
		vector<int> res;
		if (!isLeaf(root)) res.push_back(root->data);
		addLeftBoundary(root, res);
		addLeaves(root, res);
		addRightBoundary(root, res);

		for (int val : res) cout << val << " ";
	}


	void traversal() {
		cout << "Boundary Traversal : ";
		boundaryTraversal(root);
	}
};

int main() {
	BinaryTree tree;
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	tree.traversal();
	return 0;
}