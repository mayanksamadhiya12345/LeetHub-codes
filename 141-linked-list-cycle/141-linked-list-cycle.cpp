/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        // check if head is on null or head next is on null
        if(head==NULL or head->next==NULL)
        {
            return false;
        }
        
        // 2 pointer approach
        // Tortoise approach
        ListNode* slow = head;
        ListNode* fast = head;
        
        // till next->null or null is not find
        while(fast->next && fast->next->next)
        {
            slow = slow->next;       // move slow by one
            fast = fast->next->next; // move fast by two
            
            // if they collide
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
};

// Example : 
// [3,2,0,-4]

// 1. slow = 3 , fast = 3

// 2. slow = 2 , fast = 0
    
// 3. slow = 0 , fast = 2
    
// 4. slow = -4 , fast = -4     (they collide it means there is a cycle exist in the given linked list)