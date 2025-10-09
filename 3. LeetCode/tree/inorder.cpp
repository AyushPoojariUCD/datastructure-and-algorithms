#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void inorderRec(TreeNode* root, vector<int>& result) {
        if (!root) return;
        inorderRec(root->left, result);
        result.push_back(root->val);
        inorderRec(root->right, result);
    }

    vector<int> inorderIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;
        while (current != NULL || !st.empty()) {
            while (current != NULL) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            result.push_back(current->val);
            current = current->right;
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        //vector<int> result;
        //inorder(root, result);
        return inorderIterative(root);
    }
};
