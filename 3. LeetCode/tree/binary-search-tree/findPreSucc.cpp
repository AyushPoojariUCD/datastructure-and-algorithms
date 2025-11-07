class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = nullptr;
        Node* suc = nullptr;
        Node* curr = root;
        while (curr) {
            if (curr->data == key) {
                if (curr->left) {
                    Node* temp = curr->left;
                    while (temp->right)
                        temp = temp->right;
                    pre = temp;
                }
                if (curr->right) {
                    Node* temp = curr->right;
                    while (temp->left)
                        temp = temp->left;
                    suc = temp;
                }
                break;
            }
            else if (key < curr->data) {
                suc = curr;
                curr = curr->left;
            } 
            else {
                pre = curr;       
                curr = curr->right;
            }
        }
        return {pre, suc};
    }
};
