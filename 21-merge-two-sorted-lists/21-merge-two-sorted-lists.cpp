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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {       
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        ListNode* ans = NULL;
        ListNode* itr = ans;
        
        if(l1->val<=l2->val)
        {
            ans = l1;
            l1 = l1->next;
        }
        
        else
        {
            ans = l2;
            l2 = l2->next;
        }
        itr = ans;
        
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val<=l2->val)
            {
                itr->next = l1;
                l1 = l1->next;
                itr = itr->next;
            }
            else
            {
                itr->next = l2;
                l2 = l2->next;
                itr = itr->next;
            }
        }
        
        while(l1!=NULL)
        {
            itr->next = l1;
            l1 = l1->next;
            itr = itr->next;
        }
        while(l2!=NULL)
        {
            itr->next = l2;
            l2 = l2->next;
            itr = itr->next;
        }
        return ans;
    }
};