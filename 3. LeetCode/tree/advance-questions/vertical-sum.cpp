class Solution {
  public:
    vector<int> verticalSum(Node *root) {
        if (!root) return {};

        map<int, int> hdSum; // map<HorizontalDistance, Sum>
        queue<pair<Node*, int>> q; // {node, HD}
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();

            // Add node's data to its vertical line sum
            hdSum[hd] += node->data;

            // Move left (HD - 1)
            if (node->left)
                q.push({node->left, hd - 1});

            // Move right (HD + 1)
            if (node->right)
                q.push({node->right, hd + 1});
        }

        // Collect sums in order of increasing HD
        vector<int> result;
        for (auto &p : hdSum)
            result.push_back(p.second);

        return result;
    }
};
