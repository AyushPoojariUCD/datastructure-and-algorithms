class Solution {
  public:
    int getCount(Node *root, int l, int h) {
        if (!root) return 0;

        // If current node is within range
        if (root->data >= l && root->data <= h)
            return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);

        // If current node is smaller than low limit
        else if (root->data < l)
            return getCount(root->right, l, h);

        // If current node is greater than high limit
        else
            return getCount(root->left, l, h);
    }
};
