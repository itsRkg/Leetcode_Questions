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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left==right)
            return head;
        ListNode* tmp= new ListNode(1000);
        int flag=0;
        //adding a dummy node 
        if(left==1)
        {
            tmp->next=head;
            head=tmp;
            flag=1;
        }
        int count=right-left;
        left--;

        ListNode *ptr=head;
        while(--left >0)
        {
            ptr=ptr->next;
        }

        ListNode *pptr=ptr->next;
        ListNode *pst_ptr=pptr->next;
        ListNode *pre_ptr=ptr;
        while(count-- >=0)
        {
            pptr->next=pre_ptr;
            pre_ptr=pptr;
       
            pptr=pst_ptr;
            
            if(pst_ptr !=NULL)
                pst_ptr=pst_ptr->next;
        }

        pst_ptr=ptr->next;
        ptr->next=pre_ptr;
        pst_ptr->next=pptr;
        
        if(flag)
            return head->next;

        return head;
    }
};