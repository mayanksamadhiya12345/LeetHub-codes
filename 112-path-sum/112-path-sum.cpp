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
    bool hasPathSum(TreeNode* root, int sum) 
    {
        // if root is NULL then return it
        if (root == NULL) 
            return false;
        
        // if we found a path from root to leaf and pur sum has become root value then return value
        if (root->val == sum && root->left ==  NULL && root->right == NULL) 
            return true;
        
        // call recursion for left and right path , if anyone of them have you true return true
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};