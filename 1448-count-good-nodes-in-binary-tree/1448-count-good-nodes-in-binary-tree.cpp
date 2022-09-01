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
    void count(TreeNode* root,int mx,int& good)
    {
        if(!root) return;
        
        if(root->val>=mx)
        {
            good++;
            mx=root->val;
        }
        
        count(root->left,mx,good);
        count(root->right,mx,good);
        return;
    }
    
    int goodNodes(TreeNode* root) 
    {
        int good = 0;
        count(root,INT_MIN,good);
        return good;
    }
};