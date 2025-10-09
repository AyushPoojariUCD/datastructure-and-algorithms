class Solution {
  private:
    bool check(Node* root, long long minVal, long long maxVal) {
        if (!root) return true;
        
        if (root->data <= minVal || root->data >= maxVal) return false;
        
        return check(root->left, minVal, root->data) &&
               check(root->right, root->data, maxVal);
    }
    
  public:
    bool isBST(Node* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
