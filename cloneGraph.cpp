// LeetCode: https://leetcode.com/problems/clone-graph/submissions/
// Runtime: 16 ms, faster than 26.97% of C++ online submissions for Clone Graph.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Clone Graph.
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
        if (node == NULL)
            return node;
        
        queue<Node*> processing;
        processing.push(node);
        Node* cur_node;
        
        vector<bool> visited (101, false);
        vector<Node*> new_node (101, NULL);
        visited[node->val] = true;
        
        while (!processing.empty()) {
            cur_node = processing.front();
            processing.pop();
            new_node[cur_node->val] = new Node(cur_node->val, cur_node->neighbors);
            for (Node* nebr : cur_node->neighbors) {
                if (visited[nebr->val])
                    continue;
                processing.push(nebr);
                visited[nebr->val] = true;
            }
        }
        
        visited = vector<bool>(101, false);
        for (int i=1; i<101; ++i) {
            if (new_node[i] == NULL)
                continue;
            for (int j=0; j<new_node[i]->neighbors.size(); ++j) {
                new_node[i]->neighbors[j] = new_node[new_node[i]->neighbors[j]->val];
            }
        }
        
        return new_node[node->val];
        
    } // func
};
