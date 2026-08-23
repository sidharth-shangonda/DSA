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
    void cloneNodes(Node *node,unordered_map<int,Node*> &mp) {
        if (node == nullptr) return;
         Node* newNode=new Node();
         newNode->val=node->val;
         mp[node->val]=newNode;
         for(auto &neigh:node->neighbors) {
            if(!mp.count(neigh->val)) cloneNodes(neigh,mp);
         }
    }
    void addEdges(Node* node,unordered_map<int, Node*>& mp,unordered_set<int>& visited) {

        visited.insert(node->val);

        for (auto neigh : node->neighbors) {
            // Add this edge only once
            if (node->val < neigh->val) {
                mp[node->val]->neighbors.push_back(mp[neigh->val]);
                mp[neigh->val]->neighbors.push_back(mp[node->val]);
            }
            if (!visited.count(neigh->val)) {
                addEdges(neigh, mp, visited);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<int,Node*> mp;
        cloneNodes(node,mp);
        unordered_set<int> visited;
        addEdges(node,mp,visited);
        
        return mp[node->val];
    }
};