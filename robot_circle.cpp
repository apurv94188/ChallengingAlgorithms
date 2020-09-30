// LeetCode: https://leetcode.com/problems/robot-bounded-in-circle/
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Robot Bounded In Circle.
// Space Complexity O(n)

class Solution {
public:
    
    
    bool isRobotBounded(string instructions) {
        
        // if dir is N increment x pos. if dir is S decrement x pos. if dir is E increment y pos. If dir is w decrement y pos
        int inc = 1;   // inc==1 for N and E. inc==-1 for S and W

        // 1st index represent x pos. 2nd index represnt y pos
        int pos[2] = {0,0};
        
        // ix tells which inddex in pos to moodify currently
        int ix = 0;  // ix==0 mean N or S. ix==1 mean E or W
        
        //max 4 rotation is required if u want to come back at same pos.
        instructions += instructions + instructions + instructions;
        
        char curr_dir = 'N';  //current direction.   N S E W
        
        for (char step : instructions){
            switch (step) {
                case 'G':
                    // increment/decrement pos depending uppon if dir of movement
                    pos[ix] += inc;
                    break;
                case 'L':
                    // change ix or inc or both 
                    switch (curr_dir) {
                        case 'N':
                            curr_dir = 'E';
                            ix = 1;
                            break;
                        case 'S':
                            curr_dir = 'W';
                            ix = 1;
                            break;
                        case 'W':
                            curr_dir = 'N';
                            ix = 0;
                            inc = 1;
                            break;
                        case 'E':
                            curr_dir = 'S';
                            ix = 0;
                            inc = -1;
                            break;
                    }
                    break;
                case 'R':
                    // change ix or inc or both
                    switch (curr_dir) {
                        case 'N':
                            curr_dir = 'W';
                            ix = 1;
                            inc = -1;
                            break;
                        case 'S':
                            curr_dir = 'E';
                            ix = 1;
                            inc = 1;
                            break;
                        case 'W':
                            curr_dir = 'S';
                            ix = 0;
                            break;
                        case 'E':
                            curr_dir = 'N';
                            ix = 0;
                            break;
                    }
                    break;
            } // switch step
            
        } // for
        
        if (pos[0]==0 && pos[1]==0 && curr_dir=='N')
            return true;
        
        return false;
    }
};
