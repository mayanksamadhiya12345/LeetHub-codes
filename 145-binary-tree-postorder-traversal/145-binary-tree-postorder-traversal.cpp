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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        postorder(ans,root);    
        return ans;
    }
    
    void postorder(vector<int> &ans,TreeNode* root)
    {
        if(root==NULL)
            return;
        
        postorder(ans,root->left);
        postorder(ans,root->right);
        ans.push_back(root->val);
    }
};
// Inorder Traversal 
// Left -> Right -> Root 

// our aim to reach extremely left element of the tree the print it then right eleemnt and print it then root
// element then print that