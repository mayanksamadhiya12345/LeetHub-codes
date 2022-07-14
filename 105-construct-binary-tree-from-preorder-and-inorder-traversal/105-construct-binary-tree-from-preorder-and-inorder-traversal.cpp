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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        // my first job is to assign the numbering to the inorder nodes
        map<int, int> inMap; 
        for(int i=0;i<inorder.size();i++) 
        {
            inMap[inorder[i]] = i;
        }
        
        // fidning the root of the given pre and in order by using recursion
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap)
    {
        // if pointers will cross the boundary then return NULL
        if(preStart > preEnd || inStart > inEnd) return NULL;
        
        // first find the current root 
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];                      // find the place of root in Inorder  
        int numsLeft = inRoot - inStart;                    // find the number of left elements in inorder for root
        
        // check for left as well as right 
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
        
        return root;
    }
};