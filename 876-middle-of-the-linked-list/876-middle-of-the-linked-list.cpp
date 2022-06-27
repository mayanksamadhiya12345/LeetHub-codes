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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *slow=head, *fast=head;      // initializing two pointers slow and fast
        
        while (fast && fast->next)            // till the null
        {
            slow = slow->next;                // move slow by one step
            fast = fast->next->next;          // move fast by two step
        }
        return slow;
    }
};