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

	void postorderIterative(Node* root) {
		if (!root) return;
		stack<Node*> st1, st2;
		st1.push(root);
		while (!st1.empty()) {
			Node* curr = st1.top();
			st1.pop();
			st2.push(curr);
			if (curr->left) st1.push(curr->left);
			if (curr->right) st1.push(curr->right);
		}
		while (!st2.empty()) {
			cout << st2.top()->data << " ";
			st2.pop();
		}
	}

	void traversal() {
		cout << "Postorder Iterative Traversal : ";
		postorderIterative(root);
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