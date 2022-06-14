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
    ListNode* removeElements(ListNode* head, int val) 
    {
        // Assign head to curr for iteration puspose
        ListNode* curr = head;
        
        // if given head is NULL then return NULL
        if(head == NULL)
            return head;
        
        // till our current pointer or its next not gets zero
        while(curr != NULL && curr->next != NULL)
        {
            // if current next equal to given val then skip that
            if(curr->next->val == val)
            {
                curr->next = curr->next->next;
            }
            
            // if not same then do not do nothing
            else
            {
                curr = curr->next;
            }
        }
        
        // after all iteration just check for head , if its also equal to given val then return its next
        if(head->val==val) 
            return head->next;
        
        return head;
    }
};