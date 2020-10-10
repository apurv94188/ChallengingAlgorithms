class Solution {
public:
    
    unordered_map<int,int> n_freq;
    map<int,set<int>> freq_setN;
    
    int get_max_prefix() {
        
        if (freq_setN.size() > 2) // if 3 or more freq set exist - max not possible
            return -1;
        
        if (freq_setN.size() == 1){  // if only 1 freq set exist
            int freq = freq_setN.begin()->first;
            
            if (freq==1) // all unqiue num
                return freq_setN[freq].size();
            if (freq_setN[freq].size()==1)  // all num are same
                return freq;
            
        }
        
        // total freq set is 2
        auto itr_1 = freq_setN.begin();  // 1st freq
        auto itr_2 = freq_setN.rbegin(); // 2nd freq
        int min_freq = min (itr_1->first, itr_2->first);  // get min freq
        int max_freq = max (itr_1->first, itr_2->first); // get max freq
        
        int min_freq_size = freq_setN[min_freq].size();  // #ele in min freq
        int max_freq_size = freq_setN[max_freq].size(); // #ele in max freq
        
        
        int max_prefix = -1;
        if (min_freq==1 && min_freq_size==1)
            max_prefix = max_freq_size*max_freq+1;
        if (max_freq_size==1 && max_freq-min_freq==1)
            max_prefix = max(min_freq*(min_freq_size+1)+1, max_prefix);
        
        return max_prefix;
    }
    
    int maxEqualFreq(vector<int>& nums) {
        
        int max_prefix=1;
        int freq;
        for (int i=0; i<nums.size(); ++i) {
            // if num encountered before
            if (n_freq.find(nums[i]) == n_freq.end())
                n_freq.insert({nums[i], 1}); // assiign 1
            else
                ++n_freq[nums[i]];  // inc count
            freq = n_freq[nums[i]];  // new freq
            
            // if num encountered before
            // remove num from prev freq set
            if (freq != 1){
                freq_setN[freq-1].erase(nums[i]);
                if (freq_setN[freq-1].size()==0)
                    freq_setN.erase(freq-1);
            }
            
            // add num to new freq set
            if (freq_setN.find(freq) == freq_setN.end()) // if new freq set doesn't exist
                freq_setN.insert({freq, {nums[i]}});
            else  // if new freq set already exist
                freq_setN[freq].insert(nums[i]);
            
            max_prefix = max(get_max_prefix(), max_prefix);
            //cout << max_prefix << ":"<<freq<<":"<<freq_setN[freq].size() << " ";
        } // for i
        
        return max_prefix;
    }
};
