/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
bool hasCycle(ListNode *head) {
    
        ListNode *tor=head, *hare=head ;
        while(hare!=NULL && hare->next!=NULL && tor!=NULL )
        {
            hare= hare->next->next;
            tor= tor->next;
            if(hare==tor)
                return true;
        }
        return false;
    }
};