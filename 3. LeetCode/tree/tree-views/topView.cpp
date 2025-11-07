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

	void topViewIterative(Node* root) {
		if (!root) return;
		map<int, int> topMap; 
		queue<pair<Node*, int>> q;
		q.push({root, 0});
		while (!q.empty()) {
			auto [node, hd] = q.front();
			q.pop();
			if (topMap.find(hd) == topMap.end())
				topMap[hd] = node->data;
			if (node->left) q.push({node->left, hd - 1});
			if (node->right) q.push({node->right, hd + 1});
		}
		cout << "Top View (Iterative): ";
		for (auto& it : topMap)
			cout << it.second << " ";
		cout << endl;
	}

	void topViewRecursiveUtil(Node* root, int hd, int level, map<int, pair<int, int>>& m) {
		if (!root) return;
		if (m.find(hd) == m.end() || level < m[hd].second)
			m[hd] = {root->data, level};
		topViewRecursiveUtil(root->left, hd - 1, level + 1, m);
		topViewRecursiveUtil(root->right, hd + 1, level + 1, m);
	}

	void topViewRecursive(Node* root) {
		map<int, pair<int, int>> m;
		topViewRecursiveUtil(root, 0, 0, m);
		cout << "Top View (Recursive): ";
		for (auto& it : m)
			cout << it.second.first << " ";
		cout << endl;
	}

	void views() {
		topViewIterative(root);
		topViewRecursive(root);
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
