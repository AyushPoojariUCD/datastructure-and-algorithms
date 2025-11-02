#include<bits/stc++.h>
using namespace std;

// Node
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
}

// Binary Tree
class BinaryTree{
    Node* root;
    BinaryTree(){
        root = nullptr;
    }

    void insert(int val){
        Node* newNode = new Node(val);
        if(!root){
            root = newNode;
            return;
        }
        queue<Node*> q;
        q.push(newNode);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if(!node->left){
                left = newNode;
                return;
            }else q.push(node->left);
            if(!node->right){
                right = newNode;
                return;
            }else q.push(node->right);
        }
    }

    int countNodes(Node* node){
        if(!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int countLeaf(Node* node){
        if(!node) return 0;
        if(!node->left && !node->right) return 1;
        return countLeaves(node->left) + countLeaves(node->right);
    }
}

int main(){
    return 0;
}