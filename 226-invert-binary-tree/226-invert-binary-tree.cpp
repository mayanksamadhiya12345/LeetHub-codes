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
    TreeNode* invert(TreeNode* root)
    {
        if(root == NULL)
            return root;
        
        // fo to the extreme left and and right
        invert(root->left);
        invert(root->right);
        
        // swap left with right 
        swap(root->left,root->right);
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) 
    {
        // if root is NULL then  return that
        if(root==NULL)
            return root;
        
        // call the function for finding the invert of given root
        invert(root);
        
        return root;
    }
};