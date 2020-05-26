class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int p=nums[0], n=nums[0];
        int max_p = p;
        int n_first = max_p;
        int negcnt = nums[0] < 0 ? 1 : 0;
        for (int i=1; i<nums.size(); ++i) {
            
            if (nums[i] <= 0) {
                max_p = max(max_p, p);
                max_p = max(max_p, n);
                if (n_first < 0 && negcnt > 1)
                    max_p = max(max_p, n/n_first);
                if (nums[i]==0) {
                    n_first = 0;
                    negcnt = 0;
                }
                else
                    ++negcnt;
            }
            
            if (n_first == 0)
                n_first = nums[i];
            else if (n_first > 0)
                n_first *= nums[i];
            
            if (p <= 0)
                p = nums[i];
            else
                p *= nums[i];
            
            if (n == 0)
                n = nums[i];
            else
                n *= nums[i];
            
        }
        
        max_p = max(max_p, p);
        max_p = max(max_p, n);
        if (n_first < 0 && negcnt > 1)
            max_p = max(max_p, n/n_first);
        
        return max_p;
    }
};
