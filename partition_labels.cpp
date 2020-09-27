// LeetCode: https://leetcode.com/problems/partition-labels/
// Time Complexity: O(n) Beats 97.62% of the submission.
// Space Complexity: O(n)

class Solution {
public:
    
    vector<int> partitionLabels(string S) {
        vector<int> alpha (26,-1);
        vector<int> start_index;
        vector<int> output;
        int ix, i;
        
        for (i=0; i<S.size(); ++i) {
            ix = S[i]-'a';
            if (alpha[ix] == -1)
                alpha[ix] = i;
            start_index.push_back(alpha[ix]);
        }
        
        int count=0, min_ix=start_index[S.size()-1];
        i = start_index.size()-1;
        
        for (; i>=0; --i) {
            if (min_ix == i) {
                start_index[i] = ++count;
                count = 0;
                if (i!=0)
                    min_ix = start_index[i-1];
                continue;
            }
            if (start_index[i] > min_ix)
                start_index[i] = ++count;
            else if (start_index[i] < min_ix) {
                min_ix = start_index[i];
                start_index[i] = ++count;
            } else {
                start_index[i] = ++count;
            }
            //o = to_string(start_index[i]) + " " + o;
        }
        //cout << endl << o;
        i=0;
        while (i<start_index.size()) {
            output.push_back(start_index[i]);
            i += start_index[i];
        }
        
        return output;
    }
};
