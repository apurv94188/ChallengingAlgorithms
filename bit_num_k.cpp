/*
LeetCode: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
Runtime: 220 ms, faster than 86.32% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
Memory Usage: 22.6 MB, less than 5.06% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        // atleast there should be pow(2,k) bits in the s
        if (s.size() < pow(2,k))
            return false;
        
        // all num found in s will be stored here.
        unordered_set<int> found;
        // vector<bool> found((1<<k),false);  // can also be used
        
        unsigned int num=0;
        map<char,int> ctoi = {{'0',0},{'1',1}};
        
        // get num from 1st k bits
        for (int i=0; i<k; ++i) {
            num <<= 1;
            num = num | ctoi[s[i]];
        }
        
        // get a mask which used to cut off all the 32-k bits
        unsigned mask = 0;
        for (int i=0; i<k; ++i){
            mask <<= 1;
            mask |= 1;
        }
        
        found.insert(num);
        
        // keep shifting the k bit window to extract all num
        for (int i=k; i<s.size(); ++i) {
            num <<= 1;
            num |= ctoi[s[i]];
            num &= mask;
            found.insert(num);
            //cout << num << " ";
            if(found.size() == pow(2,k))
                return true;
        }
        
        return false;
    }
};
