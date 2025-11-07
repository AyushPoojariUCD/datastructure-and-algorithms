class Solution {
  private:
    Node* findLCA(Node* root, int a, int b) {
        if (!root) return nullptr;
        if (root->data == a || root->data == b) return root;
        Node* leftLCA = findLCA(root->left, a, b);
        Node* rightLCA = findLCA(root->right, a, b);
        if (leftLCA && rightLCA) return root;
        return leftLCA ? leftLCA : rightLCA;
    }

    int findLevel(Node* root, int target, int level) {
        if (!root) return -1;
        if (root->data == target) return level;
        int left = findLevel(root->left, target, level + 1);
        if (left != -1) return left;
        return findLevel(root->right, target, level + 1);
    }

  public:
    int findDist(Node* root, int a, int b) {
        Node* lca = findLCA(root, a, b);
        if (!lca) return -1; 
        int d1 = findLevel(lca, a, 0);
        int d2 = findLevel(lca, b, 0);
        return d1 + d2;
    }
};
