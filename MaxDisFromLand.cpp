class Solution {
public:
    
    
    int maxDistance(vector<vector<int>>& grid) {
        
        int nr = grid.size(), nc=grid[0].size();
        int max_dis = -1;
        
        // set all land to 0 and water to max
        for (int c=0; c<nc; ++c)
            grid[0][c] = grid[0][c] == 1 ? 0 : INT_MAX-1;
        
        // top to down
        for (int r=1; r<nr; ++r) {
            for (int c=0; c<nc; ++c) {
                if (grid[r][c] == 1)
                    grid[r][c] = 0;
                else if (grid[r-1][c] == INT_MAX-1)
                    grid[r][c] = grid[r-1][c];
                else
                    grid[r][c] = grid[r-1][c]+1;
            } // for c
        }
        
        // left to right
        for (int r=nr-1; r>=0; --r) {
            for (int c=1; c<nc; ++c) {
                grid[r][c] = min(grid[r][c-1]+1, grid[r][c]);
            }
        }
        
        
        // right to left
        for (int r=nr-1; r>=0; --r) {
            for (int c=nc-2; c>=0; --c) {
                grid[r][c] = min(grid[r][c+1]+1, grid[r][c]);
            }
        }
        
        max_dis = *(max_element(grid[nr-1].begin(), grid[nr-1].end())); // get max value of last row
        
        // bottom to top
        for (int r=nr-2; r>=0; --r) {
            for (int c=0; c<nc; ++c) {
                grid[r][c] = min(grid[r+1][c]+1, grid[r][c]);
                if (max_dis < grid[r][c])
                    max_dis = grid[r][c];
            }
        }
        
        if (max_dis >= INT_MAX-1 || max_dis == 0)
            return -1;
        return max_dis;
    }
};
