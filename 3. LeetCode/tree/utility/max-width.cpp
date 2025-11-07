class Solution {
  public:
    int maxWidth(Node* root) {
        if (!root) return 0;

        queue<Node*> q;
        q.push(root);
        
        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            maxWidth = max(maxWidth, size);
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        return maxWidth;
    }
};
