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

	void zigZagTraversal(Node* root) {
		if (!root) return;
		queue<Node*> q;
		q.push(root);
		bool leftToRight = true;

		while (!q.empty()) {
			int size = q.size();
			vector<int> row(size);
			for (int i = 0; i < size; i++) {
				Node* curr = q.front();
				q.pop();
				int index = leftToRight ? i : size - i - 1;
				row[index] = curr->data;
				if (curr->left) q.push(curr->left);
				if (curr->right) q.push(curr->right);
			}
			leftToRight = !leftToRight;
			for (int val : row) cout << val << " ";
		}
	}

	void traversal() {
		cout << "ZigZag Traversal : ";
		zigZagTraversal(root);
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