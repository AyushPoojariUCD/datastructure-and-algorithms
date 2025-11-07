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
    
    int diameterRec(Node* node,int &maxDiamter){
        if(!node) return 0;
        int lh = diameterRec(node->left,maxDiamter);
        int rh = diameterRec(node->right,maxDiamter);
        maxDiamter = max(maxDiamter,lh + rh);
        return 1 + max(lh,rh);
    }
    
    int diameter(){
        int maxDiamter = 0;
        return diameterRec(root,maxDiamter);
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
	cout << "Diameter: " << tree.diameter();
	return 0;
}