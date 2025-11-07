class Solution {
  private:
    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isCBT(Node* root, int index, int totalNodes) {
        if (!root) return true;
        if (index >= totalNodes) return false;  // violates completeness

        return isCBT(root->left, 2 * index + 1, totalNodes) &&
               isCBT(root->right, 2 * index + 2, totalNodes);
    }

    bool isMaxOrder(Node* root) {
        if (!root) return true;

        // Leaf node
        if (!root->left && !root->right)
            return true;

        // Node has only left child
        if (root->left && !root->right)
            return root->data >= root->left->data && isMaxOrder(root->left);

        // Node has both children
        return (root->data >= root->left->data &&
                root->data >= root->right->data &&
                isMaxOrder(root->left) &&
                isMaxOrder(root->right));
    }

  public:
    bool isHeap(Node* tree) {
        int totalNodes = countNodes(tree);
        if (!tree) return true;

        return isCBT(tree, 0, totalNodes) && isMaxOrder(tree);
    }
};
