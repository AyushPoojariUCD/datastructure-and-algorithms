class Solution {
  public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node* prev = nullptr;

            // Process one level
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                // Link previous node of same level to current
                if (prev) prev->nextRight = curr;
                prev = curr;

                // Push children for next level
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            // Last node of each level → NULL
            prev->nextRight = nullptr;
        }

        return root;
    }
};
