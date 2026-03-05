class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                int val = curr->val;
                
                while (curr && curr->val == val) {
                    curr = curr->next;
                }
                
                prev->next = curr;
            } 
            else {
                prev = prev->next;
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};