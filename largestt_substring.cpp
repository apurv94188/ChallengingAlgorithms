/*
Leetcode: https://leetcode.com/problems/last-substring-in-lexicographical-order/
Runtime: 40 ms, faster than 85.14% of C++ online submissions for Last Substring in Lexicographical Order.
Memory Usage: 14.4 MB, less than 5.27% of C++ online submissions for Last Substring in Lexicographical Order.
*/

class Solution {
public:
    string lastSubstring(string s) {
        
        pair<char, int> max_ix; // greattest substr - 1st char with its index
        
        int i=0,j, k;
        max_ix = {s[0],0};
        
        while (++i < s.size()) {
            
            // if lower char found than greatest char
            if (max_ix.first > s[i])
                continue;
            
            // if higher char found than greatest char
            if (max_ix.first < s[i]) {
                max_ix = {s[i],i};
                continue;
            }
            
            // if greatest char and curr char same
            // check which one is higher in lexical order
            j = max_ix.second;
            k = i;
            while (++k < s.size()) {
                // if new char is itself higest. This is start of new substring
                if (s[k] > s[i]) {
                    max_ix = {s[k], k};
                    break;
                }
                
                // if we reached at same char from where we started this comparison loop. Keep the original one
                if (++j==i)
                    --k;
                    break;
                }
                
                if (s[k] == s[j])
                    continue;
                
                if (s[k] > s[j])
                    max_ix = {s[i], i};
                
                break;
            }
            i=k;
            
        }
        
        return s.substr(max_ix.second);
    }
};
