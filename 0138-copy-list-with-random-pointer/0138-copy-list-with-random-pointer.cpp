/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL)
            return NULL;
        unordered_map<Node*,Node*> h_map;

        Node *ptr=head;   
        Node *LL= new Node(head->val);
        h_map.insert({head,LL});
        
        Node* pptr=LL;
        ptr=ptr->next;

        while(ptr!=NULL)
        {
            pptr->next= new Node(ptr->val);
            pptr=pptr->next;
            h_map.insert({ptr,pptr});
            ptr=ptr->next;
        }

        ptr=head;
        pptr=LL;

        while(ptr!=NULL)
        {
            if(ptr->random==NULL)
            {
                pptr->random=NULL;
            }
            else
            {   auto it= h_map.find(ptr->random);
                pptr->random=it->second;
            }
            pptr=pptr->next;
            ptr=ptr->next;
        }
        return LL;
    }
};