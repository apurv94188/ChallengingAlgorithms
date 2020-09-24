/* LeetCode: https://leetcode.com/problems/contains-duplicate-iii/
runtime complexity: O(n*log(k))
space complexity: O(t)
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        if (nums.size()==0 || k==0)
            return false;
        
        // holds left k elements in sorted order.
        //At index i this set will have i-k-1 to i-1 elemnts.
        set<long> sorted_n;  
        
        sorted_n.insert(nums[0]);
        
        for (int i=1; i<nums.size(); ++i) {
            // search for num equal to or next greater element in the sorted array
            auto itr = lower_bound(sorted_n.begin(), sorted_n.end(), nums[i]);
            
            // get the diff with the elemnt found
            if (itr != sorted_n.end()) {
                //cout << *itr << ":";
                if (abs((*itr) - nums[i]) <= t)
                    return true;
            }
            
            // get diff with element just before the element found.
            if (itr != sorted_n.begin()) {
                --itr;
                //cout << *itr << " ";
                if (abs((*itr) - nums[i]) <= t)
                    return true;
            }
            
            if (sorted_n.size() == k)
                sorted_n.erase(nums[i-k]);
            sorted_n.insert(nums[i]);
        }
        
        return false;
    }
};
