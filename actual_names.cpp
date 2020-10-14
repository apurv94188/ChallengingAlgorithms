/*
Leetcode: https://leetcode.com/problems/making-file-names-unique/
Runtime: 276 ms, faster than 91.62% of C++ online submissions for Making File Names Unique.
Memory Usage: 62.5 MB, less than 54.47% of C++ online submissions for Making File Names Unique.
*/
class Solution {
public:
    unordered_set<string> reserved; // actual names (system assigned) will get added to this as we move loop through the vector of names
    unordered_map<string, int> name_k;  // names with their max k value reached so far
    
    inline string get_new_name (string nm) {
        // if name encountered 1st time
        if (reserved.find(nm) == reserved.end()){
            name_k.insert({nm, 0});
            reserved.insert(nm);
            return nm;
        }
        
        //* if name already encountered  *//
        // get the max k value
        int k;
        k = name_k[nm];
        string new_name;
        while(true){
            new_name = nm + "\(" + to_string(++k) + "\)";
            if (reserved.find(new_name) != reserved.end())  // already encountered so increase k
                continue;
            name_k[nm] = k;
            reserved.insert(new_name);
            return new_name;
        }
        
    }
    
    vector<string> getFolderNames(vector<string>& names) {
        
        vector<string> output;
        int k;
        string new_name;
        
        for (string nm : names) {
            output.push_back(get_new_name(nm));
        }
        
        return output;
        
    }
};
