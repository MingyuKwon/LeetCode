/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> cloneNode;
        dfs(node, cloneNode);
        return cloneNode[node];
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& cloneNode)
    {
        if(node == nullptr) return node;
        if(cloneNode.count(node) > 0) return cloneNode[node];

        Node* newNode = new Node(node->val);
        cloneNode[node] = newNode;

        for(Node* neighbor : node->neighbors)
        {
            newNode->neighbors.push_back(dfs(neighbor, cloneNode));
        }

        return newNode;
    }
};

