#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<Node*, Node*> copies;

    // -------- DFS --------
    Node* cloneGraphDFS(Node* node) {
        if (!node) return nullptr;

        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node->val);
            for (Node* neighbor : node->neighbors) {
                copies[node]->neighbors.push_back(cloneGraphDFS(neighbor));
            }
        }
        return copies[node];
    }

    // -------- BFS --------
    Node* cloneGraphBFS(Node* node) {
        if (!node) return nullptr;

        Node* copy = new Node(node->val);
        copies[node] = copy;
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            for (Node* neighbor : curr->neighbors) {
                if (copies.find(neighbor) == copies.end()) {
                    copies[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                copies[curr]->neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;
    }

public:
    Node* cloneGraph(Node* node) {
        // --- DFS ---
        // return cloneGraphDFS(node);
        // --- BFS ---
        return cloneGraphBFS(node);
    }
};
