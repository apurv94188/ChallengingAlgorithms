class Solution {
public:
    string reverseWords(string s) {
        
        string rev_s = s;
        int left=s.size(), right=s.size(), i_rev=-1;
        while (--left>=0) {
            if (s[left] == ' ')
                continue;
            while (left-1>=0 && s[left-1] != ' ') --left;
            // left pointing to a non space char for sure
            right = left;
            if (i_rev!=-1)
                rev_s[++i_rev] = ' ';
            while (right < s.size() && s[right] != ' ')
                rev_s[++i_rev] = s[right++];
        }
        
        return rev_s.substr(0,i_rev+1);
    }
};
