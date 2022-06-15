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
class Solution 
{
public:
    ListNode* makeLL(int data)
    {
        // convert the int data to linked  list data
        ListNode* node = new ListNode(data);
        return node;
    }
    
    ListNode* deleteDuplicates(ListNode* head) 
    {
        // if there is only one or none element it means there is no duplication
        if(head==NULL || head->next==NULL)
            return head;
        
        // using the set for storing the unique elements
        set<int> freq;
        
        // store all the elements of the given LL
        while(head!=NULL)
        {
            freq.insert(head->val);
            head = head->next;
        }
        
        //make LL with elements that stored in set
        ListNode* cur = new ListNode(NULL);
        head = cur;
        for(auto &it: freq)
        {
                cur->next = makeLL(it);   // chanf into the LL node
                cur = cur->next;
        }
        
        return head->next;       
    }
};