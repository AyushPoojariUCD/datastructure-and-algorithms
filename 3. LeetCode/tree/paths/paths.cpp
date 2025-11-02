#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (!node->left) {
                node->left = newNode;
                return;
            } else q.push(node->left);

            if (!node->right) {
                node->right = newNode;
                return;
            } else q.push(node->right);
        }
    }

    Node* getRoot() { return root; }

    // -----------------------------------------------
    //  Root-to-Leaf Path Sum (check if target exists)
    // -----------------------------------------------
    bool hasPathSum(Node* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right)
            return targetSum == root->data;
        return hasPathSum(root->left, targetSum - root->data) ||
               hasPathSum(root->right, targetSum - root->data);
    }

    // -----------------------------------------------
    //  Print All Root-to-Leaf Paths
    // -----------------------------------------------
    void allPaths(Node* root, vector<int>& path) {
        if (!root) return;
        path.push_back(root->data);

        if (!root->left && !root->right) {
            for (int val : path) cout << val << " ";
            cout << endl;
        } else {
            allPaths(root->left, path);
            allPaths(root->right, path);
        }

        path.pop_back();
    }

    // -----------------------------------------------
    //  Max Path Sum (any node to any node)
    // -----------------------------------------------
    int maxPathSumUtil(Node* root, int& maxSum) {
        if (!root) return 0;
        int left = max(0, maxPathSumUtil(root->left, maxSum));
        int right = max(0, maxPathSumUtil(root->right, maxSum));
        maxSum = max(maxSum, left + right + root->data);
        return root->data + max(left, right);
    }

    int maxPathSum(Node* root) {
        int maxSum = INT_MIN;
        maxPathSumUtil(root, maxSum);
        return maxSum;
    }

    // -----------------------------------------------
    //  Min Root-to-Leaf Path Sum
    // -----------------------------------------------
    int minPathSum(Node* root) {
        if (!root) return INT_MAX;
        if (!root->left && !root->right) return root->data;
        return root->data + min(minPathSum(root->left), minPathSum(root->right));
    }

    // -----------------------------------------------
    //  Path Sum Anywhere (count all paths = target)
    // -----------------------------------------------
    int pathSumHelper(Node* root, int targetSum, long currSum, unordered_map<long, int>& prefix) {
        if (!root) return 0;
        currSum += root->data;
        int count = prefix[currSum - targetSum];
        prefix[currSum]++;
        count += pathSumHelper(root->left, targetSum, currSum, prefix);
        count += pathSumHelper(root->right, targetSum, currSum, prefix);
        prefix[currSum]--;
        return count;
    }

    int pathSumAnywhere(Node* root, int targetSum) {
        unordered_map<long, int> prefix;
        prefix[0] = 1;
        return pathSumHelper(root, targetSum, 0, prefix);
    }

    // -----------------------------------------------
    //  Print All Root-to-Leaf Paths Equal to Target (Path Sum II)
    // -----------------------------------------------
    void pathSumRootToLeaf(Node* root, int target, vector<int>& path, vector<vector<int>>& res) {
        if (!root) return;
        path.push_back(root->data);

        if (!root->left && !root->right && target == root->data) {
            res.push_back(path);
        } else {
            pathSumRootToLeaf(root->left, target - root->data, path, res);
            pathSumRootToLeaf(root->right, target - root->data, path, res);
        }

        path.pop_back();
    }

    // -----------------------------------------------
    //  Longest Root-to-Leaf Path
    // -----------------------------------------------
    vector<int> longestRootToLeaf(Node* root) {
        if (!root) return {};
        vector<int> left = longestRootToLeaf(root->left);
        vector<int> right = longestRootToLeaf(root->right);
        if (left.size() > right.size()) left.push_back(root->data);
        else right.push_back(root->data);
        return (left.size() > right.size()) ? left : right;
    }

    // -----------------------------------------------
    //  Diameter of Binary Tree (longest path in edges)
    // -----------------------------------------------
    int diameterUtil(Node* root, int& diameter) {
        if (!root) return 0;
        int lh = diameterUtil(root->left, diameter);
        int rh = diameterUtil(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }

    int diameter(Node* root) {
        int dia = 0;
        diameterUtil(root, dia);
        return dia;
    }

    // -----------------------------------------------
    //  Sum of All Root-to-Leaf Numbers
    // -----------------------------------------------
    int sumNumbers(Node* root, int curr = 0) {
        if (!root) return 0;
        curr = curr * 10 + root->data;
        if (!root->left && !root->right) return curr;
        return sumNumbers(root->left, curr) + sumNumbers(root->right, curr);
    }

    // -----------------------------------------------
    //  Path Between Two Given Nodes
    // -----------------------------------------------
    bool findPath(Node* root, vector<int>& path, int k) {
        if (!root) return false;
        path.push_back(root->data);
        if (root->data == k) return true;
        if (findPath(root->left, path, k) || findPath(root->right, path, k))
            return true;
        path.pop_back();
        return false;
    }

    vector<int> pathBetweenNodes(Node* root, int a, int b) {
        vector<int> path1, path2;
        findPath(root, path1, a);
        findPath(root, path2, b);
        int i = 0;
        while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) i++;
        vector<int> result;
        for (int j = path1.size() - 1; j >= i; j--)
            result.push_back(path1[j]);
        for (int j = i - 1; j < path2.size(); j++)
            result.push_back(path2[j]);
        return result;
    }

    // -----------------------------------------------
    //  Kth Ancestor of a Node
    // -----------------------------------------------
    Node* kthAncestorUtil(Node* root, int& k, int target) {
        if (!root) return nullptr;
        if (root->data == target) return root;

        Node* left = kthAncestorUtil(root->left, k, target);
        Node* right = kthAncestorUtil(root->right, k, target);

        if (left || right) {
            k--;
            if (k == 0) {
                cout << "Kth Ancestor: " << root->data << endl;
                k = INT_MAX;
            }
            return root;
        }
        return nullptr;
    }

    void paths() {
        vector<int> p;
        cout << "Has Path Sum (25): " << hasPathSum(root, 25) << endl;
        cout << "All Root-to-Leaf Paths:\n"; allPaths(root, p);
        cout << "Max Path Sum: " << maxPathSum(root) << endl;
        cout << "Min Path Sum: " << minPathSum(root) << endl;
        cout << "Path Sum Anywhere (Target=7): " << pathSumAnywhere(root, 7) << endl;

        vector<int> path;
        vector<vector<int>> res;
        pathSumRootToLeaf(root, 10, path, res);
        cout << "All Paths with Sum=10:\n";
        for (auto &v : res) {
            for (int x : v) cout << x << " ";
            cout << endl;
        }

        vector<int> longest = longestRootToLeaf(root);
        reverse(longest.begin(), longest.end());
        cout << "Longest Root-to-Leaf Path: ";
        for (int x : longest) cout << x << " ";
        cout << endl;

        cout << "Diameter (edges): " << diameter(root) << endl;
        cout << "Sum of Root-to-Leaf Numbers: " << sumNumbers(root) << endl;

        vector<int> between = pathBetweenNodes(root, 4, 7);
        cout << "Path Between 4 and 7: ";
        for (int x : between) cout << x << " ";
        cout << endl;

        int k = 2;
        kthAncestorUtil(root, k, 7);
    }
};

int main() {
    BinaryTree tree;
    for (int i = 1; i <= 8; i++) tree.insert(i);
    tree.paths();
    return 0;
}
