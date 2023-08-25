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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *head=NULL, *ptr=NULL;
        ListNode *ptr1=l1, *ptr2=l2;
        int carry=0;

        while(ptr1 && ptr2)
        {
            int sum = ptr1->val + ptr2->val + carry;
            carry=sum/10;
            sum=sum%10;
            
            ptr1=ptr1->next;
            ptr2=ptr2->next;

            if(head==NULL)
            {
                head= new ListNode(sum);
                ptr=head;
            }
            else
            {
                ptr->next = new ListNode(sum);
                ptr=ptr->next;
            }
        }

        while(ptr1)
        {
            int sum = ptr1->val + carry;
            carry=sum/10;
            sum=sum%10;
            
            ptr1=ptr1->next;

            if(head==NULL)
            {
                head= new ListNode(sum);
                ptr=head;
            }
            else
            {
                ptr->next = new ListNode(sum);
                ptr=ptr->next;
            }
        }

        while(ptr2)
        {
            int sum =  ptr2->val + carry;
            carry=sum/10;
            sum=sum%10;
            
            ptr2=ptr2->next;

            if(head==NULL)
            {
                head= new ListNode(sum);
                ptr=head;
            }
            else
            {
                ptr->next = new ListNode(sum);
                ptr=ptr->next;
            }
        }

        if(carry)
        {
            ptr->next= new ListNode(carry);
        }

        return head;
    }
};