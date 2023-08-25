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
    
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode *ptr=head;
        if(head==NULL)
            return head;
        
        while(ptr->next!=NULL)
        {
            int a=ptr->val;
            int b=ptr->next->val;
            
            a= __gcd(a,b);
            
           ptr->next= new ListNode(a,ptr->next);
           ptr=ptr->next->next;
        }
        
        return head;
    }
};