/*
Leetcode: https://leetcode.com/problems/valid-parenthesis-string/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parenthesis String.
Memory Usage: 6.2 MB, less than 38.52% of C++ online submissions for Valid Parenthesis String.
Solution: We count how many possible open brackets can be at each index moving from left to right.
We just keep track of max possible open brackets and minium possible ope brackets.
At each index:
  if s[i] == '(' then we increment the count of max and min by 1
  if s[i] == ')'  then we decrement the count of max and min by 1
  if s[i] == '*'  then we increment the max count by 1 (considering we replace * with '('. 
                  and decrement the min count by 1 (considering we replace * with ')'

*/
class Solution {
public:
    
    bool checkValidString(string s) {
        
        int min_open_count=0, max_open_count=0;
        
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                ++min_open_count; ++max_open_count;
            }
            else if (s[i] == ')') {
                --min_open_count; --max_open_count;
            }
            else { // c== '*'
                --min_open_count; ++max_open_count;
            }
            
            if (max_open_count < 0)
                return false;
            if (min_open_count < 0)
                min_open_count = 0;
            if (max_open_count > s.size()-i-1)
                --max_open_count;
            if (min_open_count > s.size()-i-1)
                return false;
        }
        cout << min_open_count << " " << max_open_count;
        return min_open_count == 0;
    }
};
