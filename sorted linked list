class Solution {
public:
    
    // for prioirty queue comparasion to compare the ListNode* based on value
    struct node_compare {
        bool operator()(const ListNode* left, const ListNode* right) {
            return left->val > right->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* head;
        ListNode* curr_node;
        
        priority_queue<ListNode*, vector<ListNode*>, node_compare> pq;
        
        // put all the heads of each ll in queue
        for (int i=0; i<lists.size(); ++i){
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }
        if (pq.empty())
            return NULL;
        
        head = pq.top();
        pq.pop();
        
        if (head->next) // if the linkedlist contains more than 1 element
            pq.push(head->next);
        curr_node = head;
        
        while (!pq.empty()) {
            curr_node->next = pq.top(); // next smallest element in the linkedlist
            pq.pop();
            curr_node = curr_node->next;
            if (curr_node->next) // whether we have not reached the end of linkedlist
                pq.push(curr_node->next);
        }
        
        return head;
    }
};
