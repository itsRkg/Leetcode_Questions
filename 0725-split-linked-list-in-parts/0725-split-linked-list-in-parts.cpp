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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        ListNode *ptr=head;
        vector<ListNode*> ans(k,NULL);
        
        if(head==NULL)
            return ans;

        int size=0;

        while(ptr)
        {
            ptr=ptr->next;
            size++;
        }

        ptr=head;
        if(size<=k)
        {
            ListNode *pptr=ptr->next;
            int i=0;
            while(ptr)
            {
                ptr->next=NULL;
                ans[i++]=ptr;
                ptr=pptr;
                if(pptr!=NULL)
                    pptr=pptr->next;
            }
            return ans;
        }

        int base= size/k;
        int mod= size%k;
        ListNode *pptr=ptr->next;
        int i=0;
        while(ptr)
        {
            ListNode *pptr=ptr;
            int off_set= mod>0?1:0;
            off_set+=base;
            mod--;
            while(off_set>0 && pptr)
            {
                off_set--;
                if(off_set)
                    pptr=pptr->next;
            }
            ans[i++]=ptr;
            ptr=pptr;
            pptr=pptr->next;
            ptr->next=NULL;
            ptr=pptr;
        }

        return ans;
    }
};