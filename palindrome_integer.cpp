// leetcode problem: https://leetcode.com/problems/find-the-closest-palindrome/
// will handle odd and even length separately
// three potential pandrome integer for the given integer n
// 1. mirror image from the middle index
// 2. decrement the value of left half by 1 and then take the mirror image
// 3. increment the value of left half by 1 and then take the mirror image

class Solution {
public:
    bool is_palindrome (string n) {
        for (int i=0, j=n.size()-1; i<j; ++i,--j)
            if (n[i] != n[j])
                return false;
        return true;
    }
    
    string odd_palindrome(string n) {
        int mid = n.size()/2;
        bool isPalindrome;
        long left_half_n;
        
        string palindrome, best_palindrome, new_n;
        long diff, best_diff=LONG_MAX;
        long long_n = stol(n);
        
        // mirror image from the middle index
        palindrome = n.substr(0,mid+1);
        //palindrome += n[mid];
        
        if (!is_palindrome(n)){
            // should only do this if n is not a palindrome itself
            for (int i=mid-1; i>=0; --i)
                palindrome += n[i];
            best_palindrome = palindrome;
            //cout << palindrome << endl;
            best_diff = abs(stol(palindrome) - long_n);
        }
        
        // decrement the value of left half by 1 and then take the mirror image
        left_half_n = stol(n.substr(0,mid+1));
        palindrome = to_string(left_half_n-1);
        
        for (int i=mid-1; i>=0; --i)
            palindrome += palindrome[i];
        
        diff = abs(stol(palindrome) - stol(n));
        //cout << palindrome << endl;
        if (best_diff >= diff) {
            best_palindrome = palindrome;
            best_diff = diff;
        }
        
        //increment the value of left half by 1 and then take the mirror image
        left_half_n = stol(n.substr(0,mid+1));
        palindrome = to_string(left_half_n+1);
        //palindrome += palindrome[mid];
        
        for (int i=mid-1; i>=0; --i)
            palindrome += palindrome[i];
        
        diff = abs(stol(palindrome) - stol(n));
        //cout << palindrome << endl;
        if (best_diff > diff)
            best_palindrome = palindrome;
        
        
        return best_palindrome;
    }
    
    
    string even_palindrome(string n) {
        int mid = n.size()/2-1;
        bool isPalindrome;
        long left_half_n;
        
        string palindrome, best_palindrome, new_n;
        long diff, best_diff=LONG_MAX;
        long long_n = stol(n);
        
        // mirror image from the middle index
        palindrome = n.substr(0,mid+1);
        palindrome += n[mid];
        
        if (!is_palindrome(n)){
            for (int i=mid-1; i>=0; --i)
                palindrome += n[i];
            best_palindrome = palindrome;
            //cout << palindrome << endl;
            best_diff = abs(stol(palindrome) - long_n);
        }
        
        // decrement the value of left half by 1 and then take the mirror image
        left_half_n = stol(n.substr(0,mid+1));
        palindrome = to_string(left_half_n-1);
        if (palindrome.size() == mid)
            palindrome += palindrome[mid-1]; // case ex.: 10001
        else
            palindrome += palindrome[mid];
        
        for (int i=mid-1; i>=0; --i)
            palindrome += palindrome[i];
        
        diff = abs(stol(palindrome) - stol(n));
        //cout << palindrome << endl;
        if (best_diff >= diff) {
            best_palindrome = palindrome;
            best_diff = diff;
        }
        
        //increment the value of left half by 1 and then take the mirror image
        left_half_n = stol(n.substr(0,mid+1));
        palindrome = to_string(left_half_n+1);
        palindrome += palindrome[mid];
        
        for (int i=mid-1; i>=0; --i)
            palindrome += palindrome[i];
        
        diff = abs(stol(palindrome) - stol(n));
        //cout << palindrome << endl;
        if (best_diff > diff)
            best_palindrome = palindrome;
        
        
        return best_palindrome;
    }
    
    string nearestPalindromic(string n) {
        
        if (n=="11" || n=="10")
            return "9";
        
        if (n.size()%2==0)
            return even_palindrome(n);
        else
            return odd_palindrome(n);
    }
};
