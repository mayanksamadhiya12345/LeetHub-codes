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
        if(root==NULL or p==root or q==root)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        else
            return root;
    }
};

//Step 1: Here we will use recursion, according to this problem we need to find such a lowest node that is the parent node of both given nodes

//Step 2: for this we will start call recursion from the root node if root is null or any of given node is root itself it means LCA is root itself

//Step 3: then we go to left and right respectively and where we got null in right then we return left node else we got null in left we return right node and if both are not null then we will return node it self because it means both of the nodes are under the node