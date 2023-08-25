/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteMiddle(struct ListNode* head){
struct ListNode *ptr=head,*pptr=head,*temp;
if(head->next==NULL) return NULL;
while(pptr!=NULL && pptr->next!=NULL)
{
    pptr=pptr->next->next;
    temp=ptr;
    ptr=ptr->next;
    
}
    temp->next=ptr->next;
    free(ptr);
    return head;
}