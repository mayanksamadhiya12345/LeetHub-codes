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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL or k==1)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* pre=dummy;
        ListNode* cur=dummy;
        ListNode* nex=dummy;

        // count the length of LL
        int len=0;
        while(cur->next)
        {
            len++;
            cur=cur->next;
        }
        // cout<<len<<endl;

        while(len>=k)
        {
            cur=pre->next;
            nex=cur->next;

            // we have to reverse of k size groups so change k-1 links
            for(int i=1;i<k;i++)
            {
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;
            len -= k;
        }

        return dummy->next;
    }
};