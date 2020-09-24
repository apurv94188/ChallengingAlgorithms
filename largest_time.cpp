/* LeetCode: https://leetcode.com/problems/largest-time-for-given-digits/
SOLUTION IS LITTLE COMPLICATED
array of 10 digits 0-9
itteraate over arr and increase the frequency of each digit, which is initialized to 0.
now an array of 4 integers: a[4] H,H,M,M representing HH:MM
get best max value for each index starting from left.
a[0]= possible value 2,1,0
a[1]= possible value 3,2,1,0 if a[0] is 2 otherwise 9..0
a[2]= possible value 5,4,3,2,1,0
a[3]= possible value 9..0
if at a[2] we didn't find appropriaate value then possibly we a[0]==2 and a[1] is 1 or 0;
so in that case set a[0] = 1 or 0 and then calculate again for a[1], a[2], a[3]
*/
class Solution {
public:
    
    inline int get_digit(vector<int> &digits, int i) {
        for (; i>=0; --i){
            if (digits[i]){
                --digits[i];
                return i;
            }
        }
        
        return -1;
    }
    
    string largestTimeFromDigits(vector<int>& arr) {
        vector<int> digits(10,0);
        for (int a : arr)
            ++digits[a];
        int a[4] = {0,0,0,0};
        int j=0;
        while (j<4) {
            switch(j) {
                case 0:
                    a[0] = get_digit(digits,2);
                    if (a[0] == -1)
                        return "";
                case 1:
                    a[1] = a[0] == 2 ? get_digit(digits,3) : get_digit(digits,9);
                    if (a[1] == -1)
                        return "";
                case 2:
                    a[2] = get_digit(digits,5);
                    if (a[2] == -1){ // didn't find right value
                        if (a[0] == 2){. // if a[0] is 2 then pssibly we can assign it 1 or 0 and get a valid time
                            ++digits[2]; ++digits[a[1]];
                            
                            if (digits[1])
                                a[0] = 1;
                            else if (digits[0])
                                a[0] = 0;
                            else
                                return "";
                            --digits[a[0]];
                            a[1] = 0;
                            j=1;
                            break;
                        }
                        else
                            return "";
                    }
                case 3:
                    a[3] = get_digit(digits, 9);
                    j=4;
            }
        }
        
        return to_string(a[0])+""+to_string(a[1])+":"+to_string(a[2])+""+to_string(a[3]);
    }
};
