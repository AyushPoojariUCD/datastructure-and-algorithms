class Solution {
  private:
    Node* solve(Node* root, int& k, int node, int& ans) {
        if (!root) return nullptr;
        if (root->data == node)
            return root;
        Node* left = solve(root->left, k, node, ans);
        Node* right = solve(root->right, k, node, ans);
        if (left || right) {
            k--;  
            if (k == 0) {
                ans = root->data;  
                k = -1;            
            }
            return root;
        }
        return nullptr;
    }
  public:
    int kthAncestor(Node* root, int k, int node) {
        int ans = -1;
        solve(root, k, node, ans);
        return ans;
    }
};
