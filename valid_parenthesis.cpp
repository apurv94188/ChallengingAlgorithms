class Solution {
public:
    
    int ileft=0, iright=0, max_len=0;
    
    int longestValidParantheses(string s, int i, int p_count) {
        
        while (i < s.size()) {
            if (s[i] == '(')
                ++p_count;
            else {
                if (--p_count < 0){
                    ileft=i+1;
                    p_count = 0;
                }
                else if (p_count == 0)
                    max_len = max(i-ileft+1, max_len);
            }
            ++i;
        }
        
        p_count = 0;
        iright = s.size()-1;
        i = s.size() - 1;
        while (i >= 0) {
            if (s[i] == ')')
                ++p_count;
            else {
                if (--p_count < 0){
                    iright=i-1;
                    p_count = 0;
                }
                else if (p_count == 0)
                    max_len = max(iright-i+1, max_len);
            }
            --i;
        }
        
        return max_len;
    }
    
    int longestValidParentheses(string s) {
        if (s.size() < 2)
            return 0;
        return longestValidParantheses(s,0,0);        
        
    }
};
