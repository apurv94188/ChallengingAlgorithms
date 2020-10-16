/*
Leetcode: https://leetcode.com/problems/bitwise-and-of-numbers-range/
Runtime: 8 ms, faster than 82.29% of C++ online submissions for Bitwise AND of Numbers Range.
Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Bitwise AND of Numbers Range.
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        int res = 0;
        int i = pow(2,30);  // to get the bit at ith position of m and n
        int temp;
        
        for (int j=0; j<31; ++j) {
            
            temp = m & i; // get the bit at jth position of m
            
            if (temp != (n&i)) // check the bit of n at j-th position and maatch with that of m
                break;
            res ^= temp;  // if same then put the j-th common bit at index j of res
            i >>= 1;  // shift the 1 in the i to be at j+1 pos
        }
        
        
        return res;
    }
};
