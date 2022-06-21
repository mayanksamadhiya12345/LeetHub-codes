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
class Solution 
{
public:
    vector<int> in;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    
    bool isValidBST(TreeNode* root) 
    {
        inorder(root);
        for(int i=1;i<in.size();i++)
        {
            if(in[i-1]>=in[i])
                return false;
        }
        return true;
    }
};


// for BST we know inorder is the sorted form of BST in increasing order
// so we will find out the Inorder
// then compare with previous value with current value by in[i-1]>=in[i] 
// if it is then return false because inorder is the well increasing sorted order 
// if it fails then it is not BST so return false 
// else retuen true