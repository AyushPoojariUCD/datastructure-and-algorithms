class Solution {
  private:
    Node* prev = nullptr;  
    Node* head = nullptr;  
    
    void convert(Node* root) {
        if (!root) return;
        convert(root->left);
        if (!prev) {
            head = root;
        } else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;  
        convert(root->right);
    }

  public:
    Node* treeToDLL(Node* root) {
        convert(root);
        return head;
    }
};
