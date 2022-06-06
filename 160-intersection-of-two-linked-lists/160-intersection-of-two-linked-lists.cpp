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
        
        int cnt1 = 0 , cnt2 = 0;   // for counting the length of both lists
        
        // counting the length of Linked List 1
        while(dummy1 != NULL)
        {
            cnt1++;
            dummy1 = dummy1->next;
        }
        
        // counting the length of Linked List 1
        while(dummy2 != NULL)
        {
            cnt2++;
            dummy2 = dummy2->next;
        }
        
        // aggain point our dummy1 and dummy2 to headA and headB
        dummy1 = headA;
        dummy2 = headB;
        
        // here we are finding the max & min length diff and according to that we are moving are dummy node to make both dummies equal
        int diff;
        if(cnt1 > cnt2)
        {
            diff = cnt1-cnt2;
            while(diff--)                                  // while diff not get 0 move our dummy
                dummy1 = dummy1->next;
        }
        else
        {
            diff = cnt2-cnt1;
            while(diff--)
                dummy2 = dummy2->next;
        }
        
        // till both dummmy node will not collide
        while(dummy1!=dummy2)
        {
            if(dummy1!=NULL)
            {
                dummy1 = dummy1->next;   // iterate the L1
            }
            
            
            if(dummy2!=NULL)
            {
                dummy2 = dummy2->next;   // iterate the L2
            }

        }
        return dummy1;
    }
};