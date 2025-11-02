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

    void verticalOrder(Node* root) {
        if (!root) return;
        map<int, vector<int>> nodes;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto p = q.front(); q.pop();
            Node* curr = p.first;
            int hd = p.second;
            nodes[hd].push_back(curr->data);
            if (curr->left) q.push({curr->left, hd - 1});
            if (curr->right) q.push({curr->right, hd + 1});
        }

        for (auto it : nodes) {
            for (int val : it.second)
                cout << val << " ";
        }
    }

	void traversal() {
		cout << "Vertical Order Traversal : ";
		verticalOrder(root);
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