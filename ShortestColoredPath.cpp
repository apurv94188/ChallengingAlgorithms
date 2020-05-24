class CNode {
    
    public:
    int m_iNum;
    int m_iRedDis = -1;
    int m_iBlueDis = -1;
    
    unordered_set<CNode*> red_edges;
    unordered_set<CNode*> blue_edges;
    
    CNode (int num) : m_iNum (num) {}
    
    bool reduce_bluedis (int dis) {
        if (m_iBlueDis == -1 || dis < m_iBlueDis){
            m_iBlueDis = dis;
            return true;
        }
        
        return false;
    }
    
    bool reduce_reddis (int dis) {
        if (m_iRedDis == -1 || dis < m_iRedDis){
            m_iRedDis = dis;
            return true;
        }
        
        return false;
    }
};


class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        
        vector<CNode*> vec_nodes;
        for (int i=0; i<n; ++i)
            vec_nodes.push_back(new CNode(i));
        
        for (vector<int> edge : red_edges)
            vec_nodes[edge[0]]->red_edges.insert(vec_nodes[edge[1]]);
        for (vector<int> edge : blue_edges)
            vec_nodes[edge[0]]->blue_edges.insert(vec_nodes[edge[1]]);
        
        vec_nodes[0]->reduce_bluedis(0);
        vec_nodes[0]->reduce_reddis(0);
        
        bool b_change;
        do {
            b_change = false;
            for (CNode* node : vec_nodes) {
                if (node->m_iRedDis != -1) {
                    for (CNode* nextnode : node->red_edges){
                        bool changed = nextnode->reduce_bluedis (node->m_iRedDis + 1);
                        if (changed)
                            b_change=true;
                    }
                }
                if (node->m_iBlueDis != -1) {
                    for (CNode* nextnode : node->blue_edges) {
                        bool changed = nextnode->reduce_reddis (node->m_iBlueDis + 1);
                        if (changed)
                            b_change = true;
                    }
                }
            }
            
        }while (b_change);
        
        vector<int> min_dis(n,-1);
        int i=-1;
        for_each (vec_nodes.begin(), vec_nodes.end(), [&min_dis, &i](CNode* node) {
            if (node->m_iBlueDis == -1)
                min_dis[++i] = node->m_iRedDis;
            else if (node->m_iRedDis == -1)
                min_dis[++i] = node->m_iBlueDis;
            else
                min_dis[++i] = min (node->m_iRedDis, node->m_iBlueDis);
        });
        
        
        return min_dis;
    }
};
