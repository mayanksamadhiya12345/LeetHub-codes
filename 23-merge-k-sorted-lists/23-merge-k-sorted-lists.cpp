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

// This Problem is just like flatten linked list
class Solution {
public:
    ListNode* merger(ListNode* l1,ListNode* l2)
    {
        // if any one list is NULL then return second list
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        // it will point our returnable merge list
        ListNode* tmp;
        
        // finding the min value between the l1 and l2 and point that value to our tmp
        if(l1->val <= l2->val)
        {
            tmp = l1;
            l1 = l1->next;
        }
        else
        {
            tmp = l2;
            l2 = l2->next;
        }
        
        // now after finding the min value we will start working with other list values 
        // and for that we will make a new ListNode pointer with initialized with our min value
        ListNode* tmp_res = tmp;
        while(l1!=NULL && l2!=NULL)
        {
            // if l1 is lower then assign it to tmp_res->next 
            // and move tmp_res and l1 by one
            if(l1->val <= l2->val)
            {
                tmp_res->next = l1;
                l1 = l1->next;
                tmp_res = tmp_res->next;
            }
            
            // if l2 is lower then assign it to tmp_res->next 
            // and move tmp_res and l2 by one
            else
            {
                tmp_res->next = l2;
                l2 = l2->next;
                tmp_res = tmp_res->next;
            }
        }
        
        // if l1 will not be empty
        while(l1!=NULL)
        {
            tmp_res->next = l1;
            l1 = l1->next;
            tmp_res = tmp_res->next;
        }
        
        // if l2 will not be empty
        while(l2!=NULL)
        {
            tmp_res->next = l2;
            l2 = l2->next;
            tmp_res = tmp_res->next;
        }
        
        return tmp;              // return mail refrence that is tmp  
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // if list in Empty
        if(lists.size() == 0)
            return NULL;
        
        // it will contain the very first list of list
        ListNode* res = lists[0];
        
        // this loop will merge all the lists
        for(int i=1;i<lists.size();i++)
        {
            res = merger(res,lists[i]);          // start merging 0th list with other lists
        }
        
        return res;
    }
};