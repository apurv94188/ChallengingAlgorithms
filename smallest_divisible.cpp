/*
Leetcode: https://leetcode.com/problems/smallest-integer-divisible-by-k/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Smallest Integer Divisible by K.
Memory Usage: 6.1 MB, less than 43.33% of C++ online submissions for Smallest Integer Divisible by K.

Solution:
Using basic divisor strategy:
start from 1 and keep finding the remainder until you encounter remainder as 0
Each time you encounter non-zero remainder, you multiply by 10 and add 1 to make the
new N with digits only 1s.
With this method u don't restart the computation for every N from scratch.
*/

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K%2==0 || K%5 == 0)
            return -1;
        long long int N = 1, rem;
        int len = 1;
        try {
            rem = N%K;
            while (rem) {
                N = rem*10+1;
                ++len;
                rem = N%K;
            }
        }catch(...) {return -1;}
        
        return len;
    }
};
