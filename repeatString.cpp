// Leetcode: https://leetcode.com/problems/repeated-string-match/

// Time complexity is O(n2) but space compecxity is best O(1)

// Runtime: 952 ms, faster than 9.03% of C++ online submissions for Repeated String Match.
// Memory Usage: 6.7 MB, less than 90.52% of C++ online submissions for Repeated String Match.

// solution:
// ia=pointer for string a, ib=pointer for string b, turns tell u how many string a has to be repeated, lefta=tells u starting from which index
// of a are we comparing with b
// start from ia=0, ib=0, lefta=0 keep incrementing ia and ib untill a[ia] != b[ib]
// if a[ia] != b[ib] then increment lefta by 1 and reset ia to lefta. Also, reset ib=0. And again start matchhing value at ia with value at ib.
// if u reach ia == size of a then set ia=0 and increment value of turns by 1 thus saying we have added another string of a

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int ib=0, ia=0, lefta=0, turns=1;
        while (true) {
            while (ia<a.size() && ib<b.size()) {
                if (a[ia] == b[ib]) {
                    ++ia;++ib;
                }
                else {
                    // if char doesn't match then start from the very right next index from where we started ia earlier i.e. lefta+1
                    // also remove all the repeated string a because we are starting from fresh so turns=1
                    // start comparing with b from ib=0
                    
                    if (lefta == a.size()-1)
                        return -1;
                    ia = ++lefta;
                    turns=1;
                    ib=0;
                }
            }
            if (ib==b.size())
                return turns;
            if (ia==a.size()) {
                // add another string a as we reached end of string a
                ++turns;
                ia = 0;
            }
        }
    }
};
