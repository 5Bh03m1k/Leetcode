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
    unordered_set<Node*> table;

    void makelist( Node* node)
    {
        if(node == nullptr)
            return;
        
        table.insert(node);
        
        for(auto i:node->neighbors)
        {
            if(table.find(i) == table.end())
                makelist(i);
        }

    }

    unordered_map<Node*,Node*> r_table;

    void makeNode()
    {
        
        for(auto it = table.begin() ; it != table.end() ; it++)
        {
            int r = (*it)->val;
            Node* n = new Node(r);
            r_table[*it] = n;
        }
        table.clear();
    }

    void connect_node(Node* node)
    {
        vector<Node*>al;
        if(node == nullptr)
        {
            //r_table[node]->neighbors = al;
            return;
        }
        table.insert(node);
        for(auto i:node->neighbors)
        {
            al.push_back(r_table[i]);
        }

        r_table[node]->neighbors = (al);

        for(auto i:node->neighbors)
        {
            if(table.find(i) == table.end())
                connect_node(i);
        }
    }

public:
    Node* cloneGraph(Node* node) {
        vector<vector<int>> v;
        makelist(node);
        makeNode();
        connect_node(node);
        return r_table[node];

    }
};