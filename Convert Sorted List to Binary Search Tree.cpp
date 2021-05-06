class Solution {
public:
    ListNode*prev=NULL;
    ListNode*succ=NULL;
    ListNode*mid(ListNode*head)
    {
        ListNode*prev=head;
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        if (head==NULL)
            return NULL;
        if (head->next==NULL)
        {
            TreeNode*n=new TreeNode(head->val);
            return n;
        }
        
        ListNode* m= mid(head);
        TreeNode*root=new TreeNode(m->val);
        
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(m->next);
        
        return root;
    }
};
