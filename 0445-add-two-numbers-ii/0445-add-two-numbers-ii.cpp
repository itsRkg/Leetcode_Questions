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

    ListNode* reverse_LL(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;

        ListNode *ptr= reverse_LL(head->next);
        head->next->next=head;
        head->next=NULL;
        return ptr;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
         l1=reverse_LL(l1);
         l2=reverse_LL(l2);
        
    

        ListNode* ans=NULL;
        ListNode* temp=ans;
        int sum=0,carry=0;
        while(l1!=NULL || l2!=NULL)
        {
            int dgt1=0,dgt2=0;

            if(l1!=NULL)
                dgt1=l1->val;
            
            if(l2!=NULL)
                dgt2=l2->val;
            
            sum=dgt1+dgt2+carry;
            carry=sum/10;
            sum=sum%10;

            if(ans==NULL)
            {    
                 ans= new ListNode(sum);
                
                 temp=ans;
            }
            else
            {    
                temp->next=new ListNode(sum);   
                temp=temp->next;
            }

            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;            
        }

        if(carry!=0)
            temp->next= new ListNode(carry);

        ans=reverse_LL(ans);
        return ans;
    }
};