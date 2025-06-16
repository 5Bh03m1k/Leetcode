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
private:
    unordered_map<Node*,Node*> table;
    Node* dfs(Node* node)
    {
        if(node == nullptr) return nullptr;

        Node* n = new Node(node->val);
        
        table[node] = n;

        for(auto i:node->neighbors)
        {
            if(table.find(i) == table.end())
                n->neighbors.push_back(dfs(i));
            else
                n->neighbors.push_back(table[i]);
        }

        return n;
    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);

    }
};