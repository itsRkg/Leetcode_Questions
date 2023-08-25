
struct ListNode* oddEvenList(struct ListNode* head){
struct ListNode *e_head,*even, *odd,*ptr=head;
int cnt=3;
if(head==NULL || head->next==NULL|| head->next->next==NULL) return head;

odd=head;
even=head->next;
e_head=head->next;
ptr=ptr->next->next;

while(ptr)
{
    if(cnt%2) //odd
    {
        odd->next=ptr;
        odd=odd->next;
    }
    else   //even
    {
        even->next=ptr;
        even=even->next;
    }
    ptr=ptr->next;
    cnt++;
}

    odd->next=e_head;
    even->next=NULL;
    return head;
}