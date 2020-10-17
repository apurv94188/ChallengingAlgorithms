/*
LeetCode: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
Runtime: 180 ms, faster than 99.62% of C++ online submissions for Maximum Sum BST in Binary Tree.
Memory Usage: 102.4 MB, less than 5.12% of C++ online submissions for Maximum Sum BST in Binary Tree.
*/


/*
walk through each subtree:
    max_val of left subtree
    max_val of right subtree
    if left & right subttree is BST
        m_max_sum = max(m_max_sum, left_sum, right_sum)
        
        if max_left_val < sub_root_val < min_right_val
            this subtree is  also BST
            min_val = min_left
            max_val = max_right
            return to parent the sum
        else
            return INT_MIN telling this subttree wasn't a BST

add it to the subroot val if both are BST and also max val of left 
*/

/* test cases
[1]
[1,-3,null]
[-1,4,null]
[1,-8,23]
[1,-8,-4]
[1,0,3]
[-1,8,3]
[-5,-8,-3]
[101,-8,223,-13,-5,180,300,null,-11,-7,99,102,null,null,400]
[101,-8,223,-13,-5,180,300,null,-11,-7,99,80,null,null,400]
[101,-8,223,-13,-5,180,300,null,-11,-7,99,102,null,null,400]
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
    
    int m_max_sum = 0;
    
    // return sum of the valid sub BST and if not valid then return INT_MIN
    int max_sub_BST (TreeNode* subroot, int& min_val, int& max_val) {
        
        int right_sum, left_sum;
        int max_sum = subroot->val;
        int min_left, max_left, min_right, max_right;
        
        if (subroot->left){
            left_sum = max_sub_BST(subroot->left, min_left, max_left);
            
            // if left subtree isn't BST or max val if subtree isn't less than root val
            if (left_sum == INT_MIN || max_left >= subroot->val)
                max_sum = INT_MIN;
            else {
                // if subtree was BST and also the max left subtree val < root val
                max_sum += left_sum;
                min_val = min_left;
            }
            
            if (m_max_sum < left_sum)  // if max val of left subtree is max val found till now
                m_max_sum = left_sum;
            
        } else
            min_val = subroot->val;
            
        if (subroot->right) {
            right_sum = max_sub_BST(subroot->right, min_right, max_right);
            
            if (right_sum == INT_MIN || max_sum == INT_MIN || min_right <= subroot->val)
                max_sum = INT_MIN;
            else{
                max_sum += right_sum;
                max_val = max_right;
            }
            
            if (m_max_sum < right_sum)
                m_max_sum = right_sum;
        } else
            max_val = subroot->val;
        
        //cout << subroot->val << " " << m_max_sum << " " << min_val << " " << max_sum << " "<< max_val << endl;
        return max_sum;
        
    }
    
    int maxSumBST(TreeNode* root) {
        
        int ignore_1, ignore_2;
        int x = max_sub_BST (root, ignore_1, ignore_2);
        //cout << x;
        return max(m_max_sum, x);
    }
};



