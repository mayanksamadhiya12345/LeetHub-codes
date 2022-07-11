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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        right(root,0,ans);
        return ans;
    }
    
    void right(TreeNode* root,int level,vector<int> &ans) 
    {
        if(root==NULL)
            return;
        
        // if it is the first node of the level then take it
        // then go to right because it is right side view and then check in left for other levels 
        if(level==ans.size())
        {
            ans.push_back(root->val);
        }
        
        right(root->right,level+1,ans);
        right(root->left,level+1,ans);
    }
};