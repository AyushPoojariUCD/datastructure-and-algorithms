#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <climits>
#include <functional>
using namespace std;

// ============================================================
// Node structures
// ============================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Info {
    int size;
    int minVal;
    int maxVal;
    bool isBST;
};

// ============================================================
// BST Class with ALL 30 Operations
// ============================================================
class BST {
private:

// ------------------------------------------------------------
// Q1–Q9: Core BST Operations
// ------------------------------------------------------------
    Node* insert(Node* root, int val) {
        if (!root) return new Node(val);
        if (val < root->data) root->left = insert(root->left, val);
        else if (val > root->data) root->right = insert(root->right, val);
        return root;
    }

    Node* search(Node* root, int key) {
        if (!root || root->data == key) return root;
        return key < root->data ? search(root->left, key) : search(root->right, key);
    }

    Node* findMin(Node* root) {
        while (root && root->left) root = root->left;
        return root;
    }

    Node* findMax(Node* root) {
        while (root && root->right) root = root->right;
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) return root;
        if (key < root->data) root->left = deleteNode(root->left, key);
        else if (key > root->data) root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right) { delete root; return nullptr; }
            else if (!root->left) { Node* t = root->right; delete root; return t; }
            else if (!root->right) { Node* t = root->left; delete root; return t; }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    bool checkBST(Node* root, long long minVal, long long maxVal) {
        if (!root) return true;
        if (root->data <= minVal || root->data >= maxVal) return false;
        return checkBST(root->left, minVal, root->data) && checkBST(root->right, root->data, maxVal);
    }

    Node* LCA(Node* root, int n1, int n2) {
        if (!root) return nullptr;
        if (n1 < root->data && n2 < root->data) return LCA(root->left, n1, n2);
        if (n1 > root->data && n2 > root->data) return LCA(root->right, n1, n2);
        return root;
    }

    int findFloor(Node* root, int key) {
        int floorVal = -1;
        while (root) {
            if (root->data == key) return root->data;
            if (root->data > key) root = root->left;
            else { floorVal = root->data; root = root->right; }
        }
        return floorVal;
    }

    int findCeil(Node* root, int key) {
        int ceilVal = -1;
        while (root) {
            if (root->data == key) return root->data;
            if (root->data < key) root = root->right;
            else { ceilVal = root->data; root = root->left; }
        }
        return ceilVal;
    }

// ------------------------------------------------------------
// Q10–Q20: Advanced Construction & Queries
// ------------------------------------------------------------
    Node* sortedArrayToBST(vector<int>& arr, int l, int r) {
        if (l > r) return nullptr;
        int mid = (l + r) / 2;
        Node* root = new Node(arr[mid]);
        root->left = sortedArrayToBST(arr, l, mid - 1);
        root->right = sortedArrayToBST(arr, mid + 1, r);
        return root;
    }

    Node* sortedListToBST(ListNode*& head, int n) {
        if (n <= 0) return nullptr;
        Node* left = sortedListToBST(head, n / 2);
        Node* root = new Node(head->val);
        head = head->next;
        root->left = left;
        root->right = sortedListToBST(head, n - n / 2 - 1);
        return root;
    }

    void kthSmallest(Node* root, int& k, int& ans) {
        if (!root) return;
        kthSmallest(root->left, k, ans);
        if (--k == 0) { ans = root->data; return; }
        kthSmallest(root->right, k, ans);
    }

    void kthLargest(Node* root, int& k, int& ans) {
        if (!root) return;
        kthLargest(root->right, k, ans);
        if (--k == 0) { ans = root->data; return; }
        kthLargest(root->left, k, ans);
    }

    Node* findSuccessor(Node* root, int key) {
        Node* succ = nullptr;
        while (root) {
            if (key < root->data) { succ = root; root = root->left; }
            else root = root->right;
        }
        return succ;
    }

    Node* findPredecessor(Node* root, int key) {
        Node* pred = nullptr;
        while (root) {
            if (key > root->data) { pred = root; root = root->right; }
            else root = root->left;
        }
        return pred;
    }

    int rangeSum(Node* root, int L, int R) {
        if (!root) return 0;
        if (root->data < L) return rangeSum(root->right, L, R);
        if (root->data > R) return rangeSum(root->left, L, R);
        return root->data + rangeSum(root->left, L, R) + rangeSum(root->right, L, R);
    }

    Node* trimBST(Node* root, int L, int R) {
        if (!root) return nullptr;
        if (root->data < L) return trimBST(root->right, L, R);
        if (root->data > R) return trimBST(root->left, L, R);
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }

    void inorderVec(Node* root, vector<int>& v) {
        if (!root) return;
        inorderVec(root->left, v);
        v.push_back(root->data);
        inorderVec(root->right, v);
    }

    bool findTwoSum(Node* root, int target) {
        vector<int> v; inorderVec(root, v);
        int i = 0, j = v.size() - 1;
        while (i < j) {
            int sum = v[i] + v[j];
            if (sum == target) return true;
            if (sum < target) i++; else j--;
        }
        return false;
    }

    void inorderStore(Node* root, vector<int>& vals) {
        if (!root) return;
        inorderStore(root->left, vals);
        vals.push_back(root->data);
        inorderStore(root->right, vals);
    }

    Node* buildBalancedBST(vector<int>& vals, int l, int r) {
        if (l > r) return nullptr;
        int mid = (l + r) / 2;
        Node* root = new Node(vals[mid]);
        root->left = buildBalancedBST(vals, l, mid - 1);
        root->right = buildBalancedBST(vals, mid + 1, r);
        return root;
    }

    Node* balanceBST(Node* root) {
        vector<int> vals;
        inorderStore(root, vals);
        return buildBalancedBST(vals, 0, vals.size() - 1);
    }

    bool isIdentical(Node* a, Node* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return (a->data == b->data) && isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
    }

// ------------------------------------------------------------
// Q21–Q30: Expert-Level Operations
// ------------------------------------------------------------
    void recoverBST(Node* root) {
        Node* first = nullptr; Node* middle = nullptr; Node* last = nullptr; Node* prev = nullptr;
        function<void(Node*)> inorder = [&](Node* node) {
            if (!node) return;
            inorder(node->left);
            if (prev && node->data < prev->data) {
                if (!first) { first = prev; middle = node; }
                else last = node;
            }
            prev = node;
            inorder(node->right);
        };
        inorder(root);
        if (first && last) swap(first->data, last->data);
        else if (first && middle) swap(first->data, middle->data);
    }

    Node* mergeBSTs(Node* root1, Node* root2) {
        vector<int> v1, v2;
        inorderStore(root1, v1);
        inorderStore(root2, v2);
        vector<int> merged;
        merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(merged));
        return buildBalancedBST(merged, 0, merged.size() - 1);
    }

    Node* bstFromPreorder(vector<int>& pre, int& idx, int bound = INT_MAX) {
        if (idx == pre.size() || pre[idx] > bound) return nullptr;
        Node* root = new Node(pre[idx++]);
        root->left = bstFromPreorder(pre, idx, root->data);
        root->right = bstFromPreorder(pre, idx, bound);
        return root;
    }

    Node* bstFromPostorder(vector<int>& post, int& idx, int lower = INT_MIN) {
        if (idx < 0 || post[idx] < lower) return nullptr;
        Node* root = new Node(post[idx--]);
        root->right = bstFromPostorder(post, idx, root->data);
        root->left = bstFromPostorder(post, idx, lower);
        return root;
    }

    void bstToGreaterSum(Node* root, int& sum) {
        if (!root) return;
        bstToGreaterSum(root->right, sum);
        sum += root->data;
        root->data = sum;
        bstToGreaterSum(root->left, sum);
    }

    bool findPairSum(Node* root, int target, unordered_set<int>& s) {
        if (!root) return false;
        if (s.count(target - root->data)) return true;
        s.insert(root->data);
        return findPairSum(root->left, target, s) || findPairSum(root->right, target, s);
    }

    void printRange(Node* root, int L, int R) {
        if (!root) return;
        if (root->data > L) printRange(root->left, L, R);
        if (root->data >= L && root->data <= R) cout << root->data << " ";
        if (root->data < R) printRange(root->right, L, R);
    }

    void serializeBST(Node* root, vector<int>& out) {
        if (!root) return;
        out.push_back(root->data);
        serializeBST(root->left, out);
        serializeBST(root->right, out);
    }

    Node* deserializeBST(vector<int>& data, int& i, int bound = INT_MAX) {
        if (i == data.size() || data[i] > bound) return nullptr;
        Node* root = new Node(data[i++]);
        root->left = deserializeBST(data, i, root->data);
        root->right = deserializeBST(data, i, bound);
        return root;
    }

    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    float findMedianBST(Node* root) {
        vector<int> vals; inorderStore(root, vals);
        int n = vals.size();
        if (n == 0) return 0;
        if (n % 2) return vals[n / 2];
        return (vals[n / 2 - 1] + vals[n / 2]) / 2.0;
    }

    Info largestBSTHelper(Node* root, int& ans) {
        if (!root) return {0, INT_MAX, INT_MIN, true};
        Info left = largestBSTHelper(root->left, ans);
        Info right = largestBSTHelper(root->right, ans);
        Info curr;
        curr.size = left.size + right.size + 1;
        curr.minVal = min(root->data, left.minVal);
        curr.maxVal = max(root->data, right.maxVal);
        if (left.isBST && right.isBST && root->data > left.maxVal && root->data < right.minVal) {
            curr.isBST = true;
            ans = max(ans, curr.size);
        } else curr.isBST = false;
        return curr;
    }

    int largestBSTSubtree(Node* root) {
        int ans = 0;
        largestBSTHelper(root, ans);
        return ans;
    }

public:
    Node* root;
    BST() { root = nullptr; }

    // --------------------------------------------------------
    // Public Wrappers for easy use
    // --------------------------------------------------------
    void insert(int val) { root = insert(root, val); }
    void deleteNode(int key) { root = deleteNode(root, key); }
    bool search(int key) { return search(root, key) != nullptr; }
    bool isBST() { return checkBST(root, LLONG_MIN, LLONG_MAX); }
    int minVal() { return findMin(root)->data; }
    int maxVal() { return findMax(root)->data; }
    void inorder(Node* r) { if (!r) return; inorder(r->left); cout << r->data << " "; inorder(r->right); }
    void display() { inorder(root); cout << "\n"; }
    int kthSmallest(int k) { int ans = -1; kthSmallest(root, k, ans); return ans; }
    int kthLargest(int k) { int ans = -1; kthLargest(root, k, ans); return ans; }
    Node* successor(int key) { return findSuccessor(root, key); }
    Node* predecessor(int key) { return findPredecessor(root, key); }
    int rangeSum(int L, int R) { return rangeSum(root, L, R); }
    Node* trim(int L, int R) { return trimBST(root, L, R); }
    bool hasTwoSum(int target) { return findTwoSum(root, target); }
    Node* balance() { return balanceBST(root); }
    bool identical(Node* a, Node* b) { return isIdentical(a, b); }
    void recover() { recoverBST(root); }
    void greaterSum() { int s = 0; bstToGreaterSum(root, s); }
    void printRange(int L, int R) { printRange(root, L, R); cout << "\n"; }
    float median() { return findMedianBST(root); }
    int largestBST() { return largestBSTSubtree(root); }
};

// ============================================================
// Main Driver for Testing
// ============================================================
int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder Traversal: "; tree.display();
    cout << "Min: " << tree.minVal() << " | Max: " << tree.maxVal() << "\n";
    cout << "Is BST? " << (tree.isBST() ? "Yes" : "No") << "\n";
    cout << "Kth Smallest (3): " << tree.kthSmallest(3) << "\n";
    cout << "Kth Largest (2): " << tree.kthLargest(2) << "\n";
    cout << "Range Sum [30,70]: " << tree.rangeSum(30,70) << "\n";
    cout << "Two Sum 90 Exists? " << (tree.hasTwoSum(90) ? "Yes" : "No") << "\n";
    cout << "Median of BST: " << tree.median() << "\n";
    cout << "Largest BST Subtree Size: " << tree.largestBST() << "\n";
    cout << "Nodes in Range [30,70]: "; tree.printRange(30,70);

    return 0;
}
