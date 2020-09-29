// Solution 1:
// Time complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    
    int rob(vector<int>& nums) {
        
        int i=nums.size();
        int money_p1=0, money_p2=0, money_p0=0;
        while (--i>=0) {
            money_p0 = max(money_p1, money_p2+nums[i]);
            money_p2 = money_p1;
            money_p1 = money_p0;
        }
        
        return money_p0;
    }
};


// solution 2:
// Time complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    
    vector<int> cache; //max_money if house roobbed at i_th house and there after
    
    void get_max_money(vector<int>& nums, int i) {
        if (i+2 < nums.size()) {
            if(cache[i+2]==-1)
                get_max_money(nums, i+2);
            cache[i] = nums[i] + cache[i+2];
        } else
            cache[i] = nums[i];
        
        // skip current house and check for adjusent house
        if (i+1 < nums.size()) {
            if (cache[i+1] == -1)
                get_max_money(nums, i+1);
            if (cache[i] < cache[i+1])
                cache[i] = cache[i+1];
        }
        
        return;
    }
    
    
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        cache = vector<int>(nums.size(), -1);
        
        get_max_money(nums, 0);
        return cache[0];
    }
};
