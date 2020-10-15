/*
LeetCode: https://leetcode.com/problems/can-convert-string-in-k-moves/
Runtime: 60 ms, faster than 98.64% of C++ online submissions for Can Convert String in K Moves.
Memory Usage: 17.9 MB, less than 5.26% of C++ online submissions for Can Convert String in K Moves.
*/
class Solution {
public:
    
    // gives min moves required to convert s into t
    inline int get_req_move(char s, char t) {
        
        if (s <= t)
            return t-s; // s->t
        
        // s->'z' 'z'->'a' 'a'->t
        return 'z'-s + 1 + t-'a';
    }
    
    bool canConvertString(string s, string t, int k) {
        
        if (s.size() != t.size())
            return false;
        
        // can be atmost 26 moves. Next number of moves required to satisfy this move. Each time this move is required, it will increase by 26
        vector<int> move;
        for (int i=0; i<27; ++i) move.push_back(i);
        int req_move;
        
        for(int j=0; j<s.size(); ++j) {
            
            req_move = get_req_move(s[j], t[j]);
            //cout << move[req_move] << " ";
            if (req_move == 0) // char are same
                continue;
            
            if (move[req_move] > k) // move required >k
                return false;
            
            move[req_move] += 26; //increase the move required next time by 26.
            
            
        } // for j
        
        
        return true;
    }
};
