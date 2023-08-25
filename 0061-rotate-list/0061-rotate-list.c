
struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* ptr=head,*temp;
    int count=0,rotate;
    if(head==NULL || head->next==NULL) return head;
    
    while(ptr->next!=NULL)
    {
        count++;
        ptr=ptr->next;    
    }

    temp=ptr;
    count++;
    rotate=k%count;
    rotate=count-rotate;
    ptr=head;
        
    while(rotate-1)
    {
        ptr=ptr->next;
        rotate--;
    }

    temp->next=head;
    temp=ptr->next;
    ptr->next=NULL;
    return temp;       
    
}