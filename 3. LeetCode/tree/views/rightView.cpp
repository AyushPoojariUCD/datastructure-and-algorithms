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

	void rightViewRecursive(Node* root, int level, int& maxLevel) {
		if (!root) return;
		if (level > maxLevel) {
			cout << root->data << " ";
			maxLevel = level;
		}
		rightViewRecursive(root->right, level + 1, maxLevel);
		rightViewRecursive(root->left, level + 1, maxLevel);
	}

	void rightViewIterative(Node* root) {
		if (!root) return;

		queue<Node*> q;
		q.push(root);

		while (!q.empty()) {
			int n = q.size();
			for (int i = 1; i <= n; i++) {
				Node* node = q.front();
				q.pop();
				if (i == n)
					cout << node->data << " ";
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
	}

	void rightView(Node* root) {
		int maxLevel = 0;
		cout << "Right View (Iterative): ";
		rightViewIterative(root);
		cout << endl;
		cout << "Right View (Recursive): ";
		rightViewRecursive(root, 1, maxLevel);
		cout << endl;
	}

	void views() {
		rightView(root);
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
	tree.views();
	return 0;
}
