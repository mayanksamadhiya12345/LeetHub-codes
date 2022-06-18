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
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)
            return true;
        
        return Symmetric(root->left,root->right);
    }
    
    bool Symmetric(TreeNode* p,TreeNode* q)
    {
        if(p==NULL or q==NULL)
            return p==q;
        
        if(p->val!=q->val)
            return false;
        
        // if any one of above is not returnable then we iterate ahead
        // left subtree -> root->left->right
        // right subtree -> root->right->left
        
        return Symmetric(p->left,q->right) 
            && Symmetric(p->right,q->left);
    }
};