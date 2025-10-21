class Solution {
  public:
    int minValue(Node* root) {
        if (root == NULL) 
            return -1;  
    
        // Move to the leftmost node
        while (root->left != NULL) {
            root = root->left;
        }

        return root->data;
    }
};
