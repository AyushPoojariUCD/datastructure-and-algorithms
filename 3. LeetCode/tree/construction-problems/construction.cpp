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

// Inorder
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 1. Build Tree from Inorder + Preorder
Node* buildTreeFromInPreHelper(vector<int>& preorder, int preStart, int preEnd,
                               vector<int>& inorder, int inStart, int inEnd,
                               unordered_map<int, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    Node* root = new Node(preorder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeFromInPreHelper(preorder, preStart + 1, preStart + numsLeft,
                                          inorder, inStart, inRoot - 1, inMap);
    root->right = buildTreeFromInPreHelper(preorder, preStart + numsLeft + 1, preEnd,
                                           inorder, inRoot + 1, inEnd, inMap);
    return root;
}

Node* buildTreeFromInPre(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    return buildTreeFromInPreHelper(preorder, 0, preorder.size() - 1,
                                    inorder, 0, inorder.size() - 1, inMap);
}

// 2. Build Tree from Inorder + Postorder
Node* buildTreeFromInPostHelper(vector<int>& inorder, int inStart, int inEnd,
                                vector<int>& postorder, int postStart, int postEnd,
                                unordered_map<int, int>& inMap) {
    if (inStart > inEnd || postStart > postEnd) return nullptr;

    Node* root = new Node(postorder[postEnd]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeFromInPostHelper(inorder, inStart, inRoot - 1,
                                           postorder, postStart, postStart + numsLeft - 1, inMap);
    root->right = buildTreeFromInPostHelper(inorder, inRoot + 1, inEnd,
                                            postorder, postStart + numsLeft, postEnd - 1, inMap);
    return root;
}

Node* buildTreeFromInPost(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    return buildTreeFromInPostHelper(inorder, 0, inorder.size() - 1,
                                     postorder, 0, postorder.size() - 1, inMap);
}

// 3. Construct Binary Tree from Level Order
Node* buildFromLevelOrder(vector<int> arr) {
    if (arr.empty()) return nullptr;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (i < arr.size()) {
        Node* curr = q.front();
        q.pop();

        if (i < arr.size()) {
            curr->left = new Node(arr[i++]);
            q.push(curr->left);
        }
        if (i < arr.size()) {
            curr->right = new Node(arr[i++]);
            q.push(curr->right);
        }
    }
    return root;
}

// Serialize (Level Order using 'N' for nulls)
string serialize(Node* root) {
    if (!root) return "";
    string s;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (!node) {
            s += "N ";
            continue;
        }
        s += to_string(node->data) + " ";
        q.push(node->left);
        q.push(node->right);
    }
    return s;
}

// Deserialize (Rebuild from serialized string)
Node* deserialize(string data) {
    if (data.empty()) return nullptr;
    stringstream ss(data);
    string val;
    ss >> val;

    Node* root = new Node(stoi(val));
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (!(ss >> val)) break;
        if (val != "N") {
            node->left = new Node(stoi(val));
            q.push(node->left);
        }
        if (!(ss >> val)) break;
        if (val != "N") {
            node->right = new Node(stoi(val));
            q.push(node->right);
        }
    }
    return root;
}

int main() {
    // 1. Build from Inorder + Preorder
    vector<int> inorder1 = {4, 2, 5, 1, 6, 3, 7};
    vector<int> preorder1 = {1, 2, 4, 5, 3, 6, 7};
    Node* root1 = buildTreeFromInPre(preorder1, inorder1);
    cout << "Inorder (In+Pre): "; inorder(root1); cout << endl;

    // 2. Build from Inorder + Postorder
    vector<int> postorder2 = {4, 5, 2, 6, 7, 3, 1};
    Node* root2 = buildTreeFromInPost(inorder1, postorder2);
    cout << "Inorder (In+Post): "; inorder(root2); cout << endl;

    // 3. Build from Level Order
    vector<int> levelOrder = {1, 2, 3, 4, 5, 6, 7};
    Node* root3 = buildFromLevelOrder(levelOrder);
    cout << "Inorder (Level): "; inorder(root3); cout << endl;

    // 4. Serialize & Deserialize
    string ser = serialize(root3);
    cout << "Serialized: " << ser << endl;

    Node* deserializedRoot = deserialize(ser);
    cout << "Inorder (Deserialized): "; inorder(deserializedRoot); cout << endl;

    return 0;
}
