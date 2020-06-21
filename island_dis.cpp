typedef pair<int,int> Cord;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int nr = A.size();
        int nc = A[0].size();
        int i,j;
        // get the first elemnt of the topmost island
        for (i=0; i<nr; ++i) {
            for (j=0; j<nc; ++j)
                if (A[i][j] == 1)
                    break;
            if (j!=nc)
                break;
        }
        
        queue<Cord> q_island_2; // let's call the topmost island as island_2
        queue<pair<Cord, int>> q_water;  // coordinate and dis of water elements from land 2
        
        // change the elements of topmost island (island_2) to 2 to differentiate it from other island
        q_island_2.push({i,j});
        A[i][j] = 2;
        while(!q_island_2.empty()) {
            Cord pos = q_island_2.front();
            q_island_2.pop();
            
            if (pos.first+1 != nr){
                if (A[pos.first+1][pos.second] == 1){
                    q_island_2.push({pos.first+1, pos.second});
                    A[pos.first+1][pos.second] = 2;
                }
                else if (A[pos.first+1][pos.second] == 0){
                    q_water.push({{pos.first+1, pos.second}, 1});
                    A[pos.first+1][pos.second] = 3;
                }
            }
            if (pos.second+1 != nc){
                if(A[pos.first][pos.second+1] == 1){
                    q_island_2.push({pos.first, pos.second+1});
                    A[pos.first][pos.second+1] = 2;
                }
                else if(A[pos.first][pos.second+1] == 0){
                    q_water.push({{pos.first, pos.second+1},1});
                    A[pos.first][pos.second+1] = 3;
                }
            }
            if (pos.first != 0){ 
                if(A[pos.first-1][pos.second] == 1){
                    q_island_2.push({pos.first-1, pos.second});
                    A[pos.first-1][pos.second] = 2;
                }
                else if(A[pos.first-1][pos.second] == 0){
                    q_water.push({{pos.first-1, pos.second},1});
                    A[pos.first-1][pos.second] = 3;
                }
            }
            if(pos.second != 0) {
                if (A[pos.first][pos.second-1] == 1){
                    q_island_2.push({pos.first, pos.second-1});
                    A[pos.first][pos.second-1] = 2;
                }
                else if(A[pos.first][pos.second-1] == 0){
                    q_water.push({{pos.first, pos.second-1}, 1});
                    A[pos.first][pos.second-1] = 3;
                }
            }
        }
        
        // using bfs search for island 1.
        while (!q_water.empty()) {
            auto temp = q_water.front();
            q_water.pop();
            Cord pos = temp.first;
            int dis = temp.second;
            //cout << pos.first << "," << pos.second << "-" << dis << endl;
            if(pos.first != 0){
                if (A[pos.first-1][pos.second] == 0){
                    q_water.push({{pos.first-1, pos.second},dis+1});
                    A[pos.first-1][pos.second] = 3;
                }
                if (A[pos.first-1][pos.second] == 1)
                    return dis;
            }
            if(pos.second != 0){
                if (A[pos.first][pos.second-1] == 0){
                    q_water.push({{pos.first, pos.second-1}, dis+1});
                    A[pos.first][pos.second-1] = 3;
                }
                if (A[pos.first][pos.second-1] == 1)
                    return dis;
            }
            if (pos.first+1 != nr) {
                if (A[pos.first+1][pos.second] == 0){
                    q_water.push({{pos.first+1, pos.second}, dis+1});
                    A[pos.first+1][pos.second] = 3;
                }
                else if (A[pos.first+1][pos.second] == 1)
                    return dis;
            }
            if (pos.second+1 != nc){
                if (A[pos.first][pos.second+1] == 0){
                    q_water.push({{pos.first, pos.second+1},dis+1});
                    A[pos.first][pos.second+1] = 3;
                }
                else if (A[pos.first][pos.second+1] == 1)
                    return dis;
            }
        }
        
        return -1;
    }
};
