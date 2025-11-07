class Solution {
  private:
    // Helper function to concatenate two circular doubly linked lists
    Node* concatenate(Node* leftList, Node* rightList) {
        if (!leftList) return rightList;
        if (!rightList) return leftList;

        // Find the last nodes of both lists
        Node* leftLast = leftList->left;
        Node* rightLast = rightList->left;

        // Connect the two lists circularly
        leftLast->right = rightList;
        rightList->left = leftLast;

        rightLast->right = leftList;
        leftList->left = rightLast;

        return leftList;
    }

  public:
    Node* bTreeToCList(Node* root) {
        if (!root) return nullptr;

        // Recursively convert left and right subtrees
        Node* left = bTreeToCList(root->left);
        Node* right = bTreeToCList(root->right);

        // Make the root a single-node circular DLL
        root->left = root->right = root;

        // Step 1: Merge left subtree CDLL + root
        Node* temp = concatenate(left, root);

        // Step 2: Merge with right subtree CDLL
        Node* finalList = concatenate(temp, right);

        return finalList;
    }
};
