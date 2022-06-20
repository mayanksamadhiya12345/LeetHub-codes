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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        // case 1: if our tree is NULL then return the given val as tree
        if(root==NULL)
            return new TreeNode(val);
        
        // case 2: if there is a tree that is not NULL 
        // make a cur pointer for iteration
        TreeNode* cur = root;
        while(true)
        {
            // if current value is less than the given value it means we should move to right
            if(cur->val < val)
            {
                // current right available
                if(cur->right)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            // if current value is greater than the given value it means we should move to left
            else
            {
                // current left available
                if(cur->left)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};