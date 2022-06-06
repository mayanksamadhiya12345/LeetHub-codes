/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        // if any one link list is emapty then return 0
        if(headA==NULL or headB==NULL) return NULL;
        
        ListNode* dummy1 = headA;  // for headA
        ListNode* dummy2 = headB;  // for headB
        
        // till both dummmy node will not collide
        while(dummy1!=dummy2)
        {
            if(dummy1!=NULL)
            {
                dummy1 = dummy1->next;   // iterate the L1
            }
            
            // logic behind this assign is to fill the differences 
            else
            {
                dummy1 = headB;          // if dummy1 reached to null then assign it to head OF L2
            }
            
            if(dummy2!=NULL)
            {
                dummy2 = dummy2->next;   // iterate the L2
            }
            else
            {
                dummy2 = headA;          // if dummy2 reached to null then assign it to head OF L1
            }
        }
        return dummy1;
    }
};