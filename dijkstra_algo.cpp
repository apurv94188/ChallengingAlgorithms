//LeetCode: https://leetcode.com/problems/path-with-maximum-probability/

typedef pair<int,double> NodeVal;

class Compare
{
public:
    bool operator() (NodeVal a, NodeVal b)
    {
        return a.second < b.second;
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        unordered_map<int, double> node_prob;
        unordered_map<int, vector<NodeVal>> adjMatrix;
        
        // creating adjency matrix
        for (int i=0; i<edges.size(); ++i) {
            vector<int> edge = edges[i];
            auto itr0 = adjMatrix.find(edge[0]);
            if (itr0 == adjMatrix.end())
                adjMatrix.insert({edge[0], {}});
            adjMatrix[edge[0]].push_back({edge[1], succProb[i]});
            
            auto itr1 = adjMatrix.find(edge[1]);
            if (itr1 == adjMatrix.end())
                adjMatrix.insert({edge[1], {}});
            adjMatrix[edge[1]].push_back({edge[0], succProb[i]});
        }
        
        if (adjMatrix.find(end) == adjMatrix.end())
            return 0.0;
        if (adjMatrix.find(start) == adjMatrix.end())
            return 0.0;
        
        
        // top node holds value max prob
        priority_queue<NodeVal, vector<NodeVal>, Compare> pq;
        unordered_set<int> processed;
        
        // insert start node to pq;
        pq.push({start,1.0});
        node_prob.insert(make_pair(start,1.0));
        
        int adj_node;
        double adj_prob;
        
        // start Dijkstra algo
        while (!pq.empty()) {
            // get top node with max prob found so far
            NodeVal top = pq.top();
            int node = top.first;
            double prob = top.second;
            
            if (node == end)
                return prob;
            
            pq.pop();
            
            // if node has already been processed don't process this anymore
            if (processed.find(node) != processed.end())
                continue;
            processed.insert(node);
            
            // get adjsent node and  
            for (NodeVal adj_pair : adjMatrix[node]) {
                adj_node = adj_pair.first;
                adj_prob = adj_pair.second;
                
                if (processed.find(adj_node) != processed.end())
                    continue;
                
                auto itr = node_prob.find(adj_node);
                if (itr == node_prob.end())
                    node_prob.insert({adj_node, 0.0});
                
                double new_prob = prob*adj_prob;
                // if new prob is better than previous one then add it to PriorityQueue
                if (new_prob > node_prob[adj_node]){
                    node_prob[adj_node] = new_prob;
                    pq.push(make_pair(adj_node, node_prob[adj_node]));
                }
                
            } // for adj_node
            
        } // while pq
        
        return 0.0;
    }
};
