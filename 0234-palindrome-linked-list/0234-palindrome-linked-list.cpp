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
    bool isPalindrome(ListNode* head) {
        
        struct ListNode *ptr=head, *pptr=head;
        stack<int> st;
        while(pptr!=NULL && pptr->next!=NULL)
        {
            st.push(ptr->val);
            ptr=ptr->next;
            pptr=pptr->next->next;
        }

        if(pptr!=NULL)
            ptr=ptr->next;
        while(ptr!=NULL)
        {
            if(st.top()!=ptr->val)
                return false;
            ptr=ptr->next;
            st.pop();
        }
        return true;
    }
};