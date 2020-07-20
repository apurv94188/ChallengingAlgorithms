// leet code : https://leetcode.com/problems/decode-ways/
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
// Memory Usage: 6.3 MB, less than 86.77%% of C++ online submissions for Decode Ways.

// Solution:
// Dynamic programming approach
// we can have 2 digit represeting a signle letter code
// or we can have 1 digit represting a signle letter code
// so we start with last digit. 1st sub problem is last digit.
// we move toward left and keep adding 1 digit to the sub-problem.
// when we are at an index (i.e. at each step) ->
// digit at the current index can be merged with prev digit.
// In this case we increase the total count by the count we
// had at index+2.  

class Solution {
public:
    int numDecodings(string s) {
        
        if (s[0]=='0') //edge case - 1st index can't be 0
            return 0;
        
        int prev_count = 1;
        int prev_prev_count = 1;
        
        int count_1char, count_2char;
        bool include_prev_char = true; // if we can combine right digit to make 1 letter code
        int i=s.size()-2; // we start from 2nd last digit
        if (s[i+1]=='0') {
            // if the last digit is 0 then start from 3rd last digit
            if (s[i] > '2' || s[i]=='0') // if the 2nd last digit can't be club with last digit which is 0
                return 0;
            --i;
            include_prev_char=false; // as the last digit is zero so 2nd last digit will have to be clubed with the last digit - 0
        }
        for (; i>=0; --i) {
            if (s[i]=='0'){
                if (s[i+1] == '0') // 2 consecutive 0s
                    return 0;
                if (s[i-1] > '2') // 0 can't be clubed to form a valid code as code will be greater than 26
                    return 0;
                include_prev_char = false;
                continue;
            }
            
            count_1char = prev_count;
            if (include_prev_char && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6')))
                count_2char = prev_prev_count; // valid double digit code
            else{
                if (s[i+1] != '0')
                    include_prev_char = true;
                count_2char = 0;
            }
            
            prev_prev_count = prev_count;
            prev_count = count_1char + count_2char;
            //cout << s[i] <<"="<<prev_count << " ";
        }
        
        return prev_count;
    }
};
