// Leet code: https://leetcode.com/problems/surrounded-regions/submissions/
// Runtime: 24 ms, faster than 95.18% of C++ online submissions for Surrounded Regions.
// Memory Usage: 10.3 MB, less than 58.49% of C++ online submissions for Surrounded Regions.
// solution:
// step 1: identify 'O's on boundry or connected to boundry 'O's and change them to letter 'b' using BFS
// step 2: iterate through the board index by index and change all 'O' to 'X' and all 'b' to 'O'


typedef pair<int,int> cord;
#define x first
#define y second

class Solution {
public:
    
    // change all 'O' on boundry or connected to boundry 'O' to 'b'
    void change_boundry_o(vector<vector<char>>& board) {
        int nc = board[0].size();
        int nr = board.size();
        //vector<cord> boundry_o;
        queue<cord> boundry_b; // contains all 'O' which got converted to 'b'
        
        // 1st row - identify all 'O' on the boundry
        for (int c=0; c<nc; ++c) {
            if (board[0][c] == 'O') {
                board[0][c] = 'b';
                boundry_b.push({0,c});
                //boundry_o.push_back({0,c});
            }
        }
        
        // last row  - identify all 'O' on the boundry
        for (int c=0; c<nc; ++c) {
            if (board[nr-1][c] == 'O') {
                board[nr-1][c] = 'b';
                boundry_b.push({nr-1,c});
                //boundry_o.push_back({nr-1,c});
            }
        }
        
        //last col  - identify all 'O' on the boundry
        for (int r=0; r<nr; ++r) {
            if (board[r][nc-1] == 'O') {
                board[r][nc-1] = 'b';
                boundry_b.push({r,nc-1});
                //boundry_o.push_back({nc-1,c});
            }
        }
        
        //1st col  - identify all 'O' on the boundry
        for (int r=0; r<nr; ++r) {
            if (board[r][0] == 'O') {
                board[r][0] = 'b';
                boundry_b.push({r,0});
            }
        }
        
        // bfs over boundry_b and convert all 'O' adjecent to the coordinates in this queue
        while(!boundry_b.empty()) {
            cord xy = boundry_b.front();
            boundry_b.pop();
            if (xy.y+1<nc && board[xy.x][xy.y+1] =='O') {
                board[xy.x][xy.y+1] = 'b';
                boundry_b.push({xy.x, xy.y+1});
            }
            if (xy.y-1>=0 && board[xy.x][xy.y-1] =='O') {
                board[xy.x][xy.y-1] = 'b';
                boundry_b.push({xy.x, xy.y-1});
            }
            if (xy.x+1<nr && board[xy.x+1][xy.y] =='O') {
                board[xy.x+1][xy.y] = 'b';
                boundry_b.push({xy.x+1, xy.y});
            }
            if (xy.x-1>=0 && board[xy.x-1][xy.y] =='O') {
                board[xy.x-1][xy.y] = 'b';
                boundry_b.push({xy.x-1, xy.y});
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.size()<3 || board[0].size()<3)
            return;
        
        int nc = board[0].size();
        int nr = board.size();
        
        // change all 'O' on boundry or connected to boundry 'O' to 'b'
        change_boundry_o(board);
        
        // iterate through each index
        // change all the 'O' to 'X' as they would be 'O' which are not connected to boundry 'b'
        // change all the 'b' to 'O'
        for (int r=0; r<nr; ++r) {
            for (int c=0; c<nc; ++c){
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                else if (board[r][c] == 'b')
                    board[r][c] = 'O';
            }
        }
        
    }
};
