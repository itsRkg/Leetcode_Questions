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
    ListNode* reverseList(ListNode* head) {
       if(head==NULL || head->next==NULL) return head;

       struct ListNode *ptr=head, *pstptr=head->next,*pptr=head->next->next;

       while(pstptr)
       {
           pstptr->next=ptr;
           ptr=pstptr;
           pstptr=pptr;
           if(pstptr)
            pptr=pstptr->next;
       }
       head->next=NULL;
       return ptr;
    }
};