/* Leetcode: https://leetcode.com/problems/rotate-list/
Solution:
  Rotate list by k
  Find the last node to get the length. Check if len < k and if it is then find the real k by k%len.
  Find the node which should be last node after the rotation. It will be at index len-k.
  Make point the current last node to the 1st node. Reach out to the len-k node and make it point to null
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0 || head->next== NULL)
            return head;
        
        int len;
        int i = k;
        ListNode* old_last_node = head;  // node which is the last node currently
        ListNode* new_last_node = head; // node that is suppose to be last after the rotation
        
        // find the length of list or the kth node in the list. Whichever coome first
        while (old_last_node->next && i>0){
            old_last_node = old_last_node->next;
            --i;
        }
        
        // case where length of list is greater than k
        if (i==0) {
            // reach out to last node
            // also keep shifting the old_last_node to maake it reach to the node which will be the last node
            while (old_last_node->next) {
                new_last_node = new_last_node->next;
                old_last_node = old_last_node->next;
            }
            old_last_node->next = head;
            head = new_last_node->next;
            new_last_node->next = NULL;
            
            return head;
        }
        
        //if (old_last_node->next == NULL) {
        len = k-i+1;
        k = k%len;
        k = len - k;  // node index which will be the last node
        
        old_last_node->next = head;
        while (--k)
            new_last_node = new_last_node->next;
        head = new_last_node->next;
        new_last_node->next = NULL;
        
        return head;
    }
};
