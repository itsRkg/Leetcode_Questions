/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    struct ListNode* ptr=list1, *pptr=list2, *new=NULL,*head,*temp;
    if(list1==NULL && list2==NULL) return NULL;
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    head=malloc(sizeof(struct ListNode));
    new=head;
    while(ptr!=NULL && pptr!=NULL)
    {
        temp=new;
        if(ptr->val<=pptr->val)
        {
            new->val=ptr->val;
            new->next=malloc(sizeof(struct ListNode));
            new=new->next;
            ptr=ptr->next;
            
        }
        else
        {
            new->val=pptr->val;
            new->next=malloc(sizeof(struct ListNode));
            new=new->next;
            pptr=pptr->next;
        }
        
    }
    while(ptr!=NULL && pptr==NULL)
    {
            new->val=ptr->val;
            new->next=malloc(sizeof(struct ListNode));
            temp=new;
            new=new->next;
            ptr=ptr->next;
    }
    while(pptr!=NULL && ptr==NULL)
    {
            new->val=pptr->val;
            new->next=malloc(sizeof(struct ListNode));
            temp=new;
            new=new->next;
            pptr=pptr->next;
    }
    temp->next=NULL;
    free(new);
    return head;
}

struct ListNode* divide(struct ListNode** lists, int p, int r)
{
    int q=(p+r)/2;
    struct ListNode *L1,*L2;
    if(p<r)
    {
       L1=divide(lists,p,q);
       L2=divide(lists,q+1,r);
       return mergeTwoLists(L1,L2);
    }
    else
        return lists[p];
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if(listsSize==0) return NULL;
    
    return divide(lists,0,listsSize-1);
}