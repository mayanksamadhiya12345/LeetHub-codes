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
        //3 pointer approach(like merge sort)
        //if any one of the LinkedList is NULL or both are null
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        //if both contains elements: ready three pointers
        //one for the final LinkedList in that we gonna merge both and 2 for comparing the given LL  (head,l1,l2) 
         
        ListNode* head = NULL;    //this will help to return head as ans
        ListNode* i = NULL;       //help in iteration or making the final LinkedList
    
        // find out which first element is lesser out of l1 and l2 
        // and after finding, assign it to head and also for i for iteration
        if(l1->val <= l2->val)
        {     
            head = l1;          //head: used as a head for Final LL
            l1 = l1->next;      //L1 pointer
        }        
        else
        {
            head = l2;
            l2 = l2->next;      //L2 pointer
        }
        i = head;               // also assign for i for iteration 
        
        
        //compare and store elements in ascending order by comaparison L1 & L2
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                i->next = l1;
                i = i->next;
                l1 = l1->next;
            }
                
            
            else
            {
                i->next = l2;
                i = i->next;
                l2 = l2->next;
            }
        }
        
        //if any Linkedlist remains empty
        while(l1!=NULL)
        {
            i->next = l1;
            i  = i->next;
            l1 = l1->next;
        }
        while(l2!=NULL)
        {
            i->next = l2;
            i  = i->next;
            l2 = l2->next;
        }
        
        return head;
                
    }
};