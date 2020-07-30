/*
leetcode: https://leetcode.com/problems/wiggle-sort-ii/submissions/
Runtime: 44 ms, faster than 86.75% of C++ online submissions for Wiggle Sort II.
Memory Usage: 17.1 MB, less than 92.42% of C++ online submissions for Wiggle Sort II.

Solution:
starting from index 1 moving right, we validate the current index (index 'i') by checking 
the values at adjucent indices.
If they don't allign then we swap the value with 'i+1' index and validate index 'i'.
If failed then we swap value with 'i-1' index and validate both inex 'i-1' and 'i'
If failed then we look for appropriate value beyound index 'i+1'.
starting from rep='i+2' we keep checking if swaping values at 'i' and 'rep' can be swapped.
If not then check by swapping 'rep' and 'i+1'.
If we don't get the right value till we reach end of 'num', then we set 'rep' to 0 and
start searching from 0 index. But this time we also make sure whatever value is swaped at
'rep' index, should be validated first.
*/

//#define DEBUG true;

class Solution {
public:
    
    inline void swap(vector<int>& num, int i, int j){
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
    
    // validate that if we set num[i] = a then will the adjucent value go as per rules 
    inline bool check_swap(vector<int>& num, int i, int a) {
        if (i%2){
            if (num[i-1] < a && (i+1==num.size() || a > num[i+1]))
                return true;
        }
        else {
            if ((i==0 || num[i-1] > a) && (i+1==num.size() || a < num[i+1]))
                return true;
        }
        
        return false;
    }
    
    // validate if adjucent values at index i are as per the rules
    inline bool validate(vector<int>& num, int i) {
        if (i%2){
            if (num[i-1] < num[i] && (i+1==num.size() || num[i] > num[i+1]))
                return true;
        }
        else {
            if ((i==0 || num[i-1] > num[i]) && (i+1==num.size() || num[i] < num[i+1]))
                return true;
        }
        
        return false;
    }
    
    void wiggleSort(vector<int>& num) {
        int ns = num.size();
        if(ns < 2)
            return;
        int i, rep=-1;
        bool docheck = false;
        
        for (int i=0; i<ns-1; ++i) {
            #ifdef DEBUG
                cout << endl << i << "::";
                for (int a : num)
                    cout << a << " ";
                cout << "::";
            #endif
            
            if (validate(num, i))
                continue;
            
            swap(num, i, i+1);
            if (validate(num, i))
                continue;
            
            if (i!=0){
                swap(num, i, i-1);
                if (validate(num, i-1) && validate(num, i))
                    continue;
                swap(num, i, i-1);
            }
            
            swap(num, i, i+1);
            
            if (rep==-1 || rep < i+1)
                rep = i+1;
            
            // we didn't get desired value by swaping with adjucent values
            // so we will swap with values beyound index 'i+1'
            int begin = rep;
            while(true) {
                ++rep;
                if (rep>=ns) {
                    rep = 0;
                    docheck=true;
                }
                #ifdef DEBUG
                    cout << rep << " ";
                #endif
                
                // swap i and rep and validate
                if ((!docheck || check_swap(num, rep, num[i])) && check_swap(num, i, num[rep])){
                    swap(num, i, rep);
                    break;
                }
                
                // swap i+1 and rep and validate index i
                if (i+1 < ns && (!docheck || check_swap(num, rep, num[i+1]))){
                    swap(num, i+1 ,rep);
                    if(validate(num, i))
                        break;
                    swap(num, i+1, rep);
                }
                
            }
        }
     
    }
};
