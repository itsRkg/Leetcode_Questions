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
    
 ListNode* removeNthFromEnd( ListNode* head, int n)
 {
        ListNode * temp=head;
        int count=0;
        if(head==NULL)
            return head;

        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        count=count-n;
        temp=head;
        if(count==0)
            return temp->next;
        
        while(--count>0)
            temp=temp->next;
        
        if(temp->next==NULL)
            return NULL;
        
        temp->next=temp->next->next;
        return head;
    }
};