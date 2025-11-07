class Solution {
  private:
    Node* buildBST(vector<int>& arr, int start, int end) {
        if (start > end) return nullptr;

        int mid = (start + end) / 2; // middle element

        Node* root = new Node(arr[mid]);

        // recursively construct left and right subtrees
        root->left = buildBST(arr, start, mid - 1);
        root->right = buildBST(arr, mid + 1, end);

        return root;
    }

  public:
    Node* sortedArrayToBST(vector<int>& arr) {
        return buildBST(arr, 0, arr.size() - 1);
    }
};
