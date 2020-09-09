// LeetCode: https://leetcode.com/problems/jump-game/
// Runtime: 20 ms, faster than 83.65% of C++ online submissions for Jump Game.
// Memory Usage: 13.1 MB, less than 22.62% of C++ online submissions for Jump Game.

/*Solution:
last_good_ix var represents the next nearest index (on the right side) which can help reach the last index either directly or using further good indices which are on the riight
Moving from right, check if the current_index + index_val >= nearest good index (right side). If yes then then the current iindex becomes the last_good_ix.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int last_good_ix = nums.size()-1,i;
        for (i=nums.size()-2; i>=0; --i)
            if (i+nums[i] >= last_good_ix)
                last_good_ix = i;
        return last_good_ix==0;
    }
};
