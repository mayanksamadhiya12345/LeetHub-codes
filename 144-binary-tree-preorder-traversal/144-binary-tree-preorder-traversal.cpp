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
    vector<int> help(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL)
            return ans;
        
        ans.push_back(root->val);
        help(root->left,ans);
        help(root->right,ans);
        return ans;
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        // preorder = root -> left -> right
         
        vector<int> ans;
        return help(root,ans);
        
        
    }
    
    
};
// Inorder Traversal 
// Root -> Left -> Right
// By using a single stack
