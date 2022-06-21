/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        // if root is null then return root itself
        if(root==NULL)
            return root;
        
        // if both the nodes lies on the left side then go to the left side
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        
        // if both the nodes lies on the right side then go to the right side
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        
        // if both the nodes not on the right side or not on the left side 
        // it means they are both side and root is the LCA for those nodes
        return root;
    }
};