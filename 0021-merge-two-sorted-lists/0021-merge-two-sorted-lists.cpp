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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *ptr1=list1;
        ListNode *ptr2=list2;
        ListNode *head=NULL, *ptr=NULL;

        while(ptr1 && ptr2)
        {
            int data;
            if(ptr1->val<=ptr2->val)
            {
                data=ptr1->val;
                ptr1=ptr1->next;
            }
            else
            {
                data=ptr2->val;
                ptr2=ptr2->next;
            }

            if(head==NULL)
            {
                head= new ListNode(data);
                ptr=head;
            }
            else
            {
                ptr->next= new ListNode(data);
                ptr=ptr->next;
            }
        }

       if(ptr1)
       {   
           if(head)  
                ptr->next=ptr1;
           else
                head=ptr1;
       }
       if(ptr2)
        {
            if(head)  
                ptr->next=ptr2;
           else
                head=ptr2;
        }
       return head;
    }
};