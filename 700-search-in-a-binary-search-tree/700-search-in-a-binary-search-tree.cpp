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
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        // check till root is not null and root->val is not equal to the desired value
        while(root != NULL && root->val != val)
        {
            // if our desired value is less than the root valur then move to the left
            if(root->val > val)
                root = root->left;
            // if our desired value is less than the root valur then move to the left
            else
                root = root->right;
        }
        // after founding the value return the root
        return root;
    }
};