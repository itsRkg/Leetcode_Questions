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

    ListNode* reverseList(ListNode* head, int k)
    {
        ListNode *ptr=head,*pptr=head->next;
        
        //iterate k-1 times as k-1 pointers only is needed to be reversed
        while(--k)
        {
            ListNode *tmp=pptr->next;
            pptr->next=ptr;
            ptr=pptr;
            pptr=tmp;
        }
        head->next=NULL;
        return ptr;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int count=0;

        ListNode *ptr=head;
        while(count<k && ptr)
        {
            count++;
            ptr=ptr->next;
        }

        if(count==k)
        {
            ListNode *new_head = reverseList(head,k);  
            head->next = reverseKGroup(ptr,k);
            return new_head;
        }

        return head;
    }
};