class Solution {
  private:
    // Step 1: Create parent mapping and find target node
    Node* createParentMap(Node* root, int target, unordered_map<Node*, Node*>& parent) {
        queue<Node*> q;
        q.push(root);
        Node* targetNode = nullptr;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->data == target)
                targetNode = curr;

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return targetNode;
    }

    // Step 2: BFS to simulate burning process
    int burnTree(Node* targetNode, unordered_map<Node*, Node*>& parent) {
        queue<Node*> q;
        unordered_map<Node*, bool> visited;
        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool burnedSomething = false;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                // Burn left child
                if (curr->left && !visited[curr->left]) {
                    burnedSomething = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }

                // Burn right child
                if (curr->right && !visited[curr->right]) {
                    burnedSomething = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }

                // Burn parent
                if (parent[curr] && !visited[parent[curr]]) {
                    burnedSomething = true;
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }

            // Increment time only if some nodes burned this second
            if (burnedSomething)
                time++;
        }

        return time;
    }

  public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        Node* targetNode = createParentMap(root, target, parent);

        return burnTree(targetNode, parent);
    }
};
