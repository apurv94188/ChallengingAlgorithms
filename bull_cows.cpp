/*
LeetCode: https://leetcode.com/problems/bulls-and-cows/
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> secret_count (10,0);
        vector<int> bull_count (10,0);
        vector<int> cow_count (10,0);
        
        for (char s : secret)
            ++secret_count[s-'0'];
        
        
        
        int gnum, snum;
        for (int i=0; i<guess.size(); ++i) {
            
            gnum = guess[i] - '0';
            snum = secret[i] - '0';
            
            if (gnum==snum) {
                // bull
                if (secret_count[gnum] == bull_count[gnum]+cow_count[gnum])  // already encountered enough gnum digit that means atleast one must have been cow
                    --cow_count[gnum];
                ++bull_count[gnum];
            } else {
                //cow
                if (secret_count[gnum] > bull_count[gnum]+cow_count[gnum])
                    ++cow_count[gnum];
            }
        }
        
        int A=0, B=0;
        for (int i=0; i<=9; ++i) {
            A += bull_count[i];
            B += cow_count[i];
        }
        
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
