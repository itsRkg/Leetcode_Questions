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
    
    int double_ll(ListNode* head)
    {
        if(head==NULL)
            return 0;
        
        int carry= double_ll(head->next);
        int dgt= head->val*2+carry;
        head->val=dgt%10;
        return dgt/10;        
    }
    
    ListNode* doubleIt(ListNode* head) {
        
        int carry=double_ll(head);
        
        if(carry==0)
            return head;
        
        ListNode* ptr= new ListNode(carry,head);
        return ptr;
    }
};