// leetcode solution: https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
// Runtime: 232 ms, faster than 94.61% of C++ online submissions for Find Two Non-overlapping Sub-arrays Each With Target Sum.
// Memory Usage: 71.4 MB, less than 96.69% of C++ online submissions for Find Two Non-overlapping Sub-arrays Each With Target Sum.

/* Solution:
Step 1: Get all the subarray with sum == target
Step 2: Get 2 non-overlapping subarray with least lenght

Step 1 (in detail):
starting from left with 1st index, add the value to curr_sum (sub-array sum).
take 2 ptr: 'il' (points to start of current sub-array) and 'ir'(points to end of current sub-array)

while curr_sum > target:
  keep deducting leftmost element in sub-array and increment the 'il' pointer until your curr_sum <= target

if curr_sum  == target
  change the value at left most index to lenght of this sub-array
  and increment pointer 'il'

if curr_sum < target
  increase 'ir'
  
run this until your 'ir' reaches end of array

By the end we have modified the array where each element represents size of subarray which sums to target, starting from that index
if the value is 10000 then you cannot get subarray starting from that index.

*/

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int curr_sum = arr[0];
        int il = 0, ir=0; // i left
        while(ir<arr.size()) {
            // keep removing elment from left in sub array until curr_sum is within target values
            while (curr_sum > target) {
                curr_sum -= arr[il];
                arr[il] = 100000;
                //cout << arr[il] << "+";
                if (++il > ir)
                    break;
            }
            if (curr_sum == target){
                curr_sum -= arr[il];  // prepare for next sub-array
                arr[il] = ir-il+1;  // tells size of sub-array starting from 'il' index which sums uopto 'target'
                //cout << arr[il] << "-";
                ++il;
                if (il > ir){
                    if (++ir < arr.size())   // add new elemnt to subarray from right
                        curr_sum += arr[ir];
                }
                
            }
            else{ // curr_sum < target
                if (++ir < arr.size())
                    curr_sum += arr[ir];    
            }
            
        } // for loop
        
        while (il < arr.size())
            arr[il++] = 100000;  // no sub-array starting from this index can be formed whose sum == target
            
        //cout << endl;
        int min_len = 100000; // min length sub-array encountered so far starting from right
        int output = 100001;  // min lenght sum of 2 sub-array starting from right
        for (int i=arr.size()-1; i>=0; --i) {
            if (arr[i] < 100000) {
                // arr[i+arr[i]] gives you the min length subarray which is encountered on the right side
                // and is also not overlapping
                if (i+arr[i] < arr.size() && arr[i] + arr[i+arr[i]] < output)
                    output = arr[i] + arr[i+arr[i]];
            }
            
            if (arr[i] < min_len)
                min_len = arr[i];
            else
                arr[i] = min_len;
            //cout << min_len << " " << output << " " << arr[i] << endl;
        }
        
        return output == 100001 ? -1 : output;
    } // func end
};
