
struct ListNode* reverseList(struct ListNode* head,int k)
{
    struct ListNode *ptr,*temp,*pstptr;
    if(head==NULL) return head;
    if(head->next==NULL) return head;
    
    ptr=head;
    pstptr=head->next;
    temp=pstptr->next;
    while(pstptr!=NULL && k!=0)
    {
        k--;
        pstptr->next=ptr;
        ptr=pstptr;
        pstptr=temp;
        if(pstptr!=NULL)
            temp=pstptr->next;        
    }
    head->next=pstptr;
 
    return ptr;
    
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
int n=0,p,i=k-1;
struct ListNode* ptr;

ptr=head;
if(head==NULL) return NULL;
while(ptr!=NULL)
{
    n++;
    ptr=ptr->next;
}
if(k>n) return head;

    
    struct ListNode *temp,*pstptr;
  
    if(head->next==NULL) return head;
    
    ptr=head;
    pstptr=head->next;
    temp=pstptr->next;
    while(pstptr!=NULL && i!=0)
    {
        i--;
        pstptr->next=ptr;
        ptr=pstptr;
      
        pstptr=temp;
        if(pstptr!=NULL)
            temp=pstptr->next;
        
    }
    head->next=pstptr;
    temp=head;
    head=ptr;
    ptr=temp;;
p=n/k;
p--;
while(p!=0)
{
    temp=ptr->next;
    ptr->next=reverseList(ptr->next,k-1);
    ptr=temp;

    p--;
}
    return head;
}