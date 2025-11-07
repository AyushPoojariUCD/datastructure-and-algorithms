class Solution {
    bool isSymmetricUtil(Node* a, Node* b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        return (a->data == b->data) &&
               isSymmetricUtil(a->left, b->right) &&
               isSymmetricUtil(a->right, b->left); 
    }
  public:
    bool isSymmetric(Node* root) {
        if (!root) return true;
        return isSymmetricUtil(root->left,root->right);
    }
};