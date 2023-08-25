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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    TreeNode* build_bst(vector<int> nums, int l, int r)
    {
        if(l>r)
            return NULL;

        int mid= (l+r)/2;
        
        TreeNode* root= new TreeNode(nums[mid]);
        root->left= build_bst(nums,l,mid-1);
        root->right= build_bst(nums,mid+1,r);

        return root;
    }
    

    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int> nums;
        ListNode *ptr=head;
        while(ptr)
        {
            nums.push_back(ptr->val);
            ptr=ptr->next;
        }

        return build_bst(nums,0,nums.size()-1);

    }
};