//LeetCode: https://leetcode.com/contest/weekly-contest-207/problems/maximum-non-negative-product-in-a-matrix/

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        vector<vector<long>> grid_min;
        vector<vector<long>> grid_max;
        int r,c;
        long a,b,d;
        for (r=0; r<grid.size(); ++r) {
            grid_min.push_back(vector<long>(grid[r].size(), INT_MAX));
            grid_max.push_back(vector<long>(grid[r].size(), INT_MIN));
            for (c=0; c<grid[r].size(); ++c) {
                if (r==0 && c==0) {
                    grid_min[0][0] = grid[0][0];
                    grid_max[0][0] = grid[0][0];
                }
                if (c>0){
                    a = grid_min[r][c-1]*grid[r][c];
                    b = grid_max[r][c-1]*grid[r][c];
                    grid_min[r][c] = a<b ? a : b;
                    grid_max[r][c] = a>b ? a : b;
                }
                if (r>0) {
                    a = grid_min[r-1][c]*grid[r][c];
                    b = grid_max[r-1][c]*grid[r][c];
                    d = a<b ? a : b;
                    grid_min[r][c] = grid_min[r][c] < d ? grid_min[r][c] : d;
                    d = a>b ? a : b;
                    grid_max[r][c] = grid_max[r][c] > d ? grid_max[r][c] : d;
                }
                
                //cout << grid_min[r][c] << ":" << grid_max[r][c] << " ";
                
            } // for col
        } // for row
        
        int e = (grid_max[grid.size()-1][grid[0].size()-1])%(1000000000+7);
        return max(-1, e);
    }
};
