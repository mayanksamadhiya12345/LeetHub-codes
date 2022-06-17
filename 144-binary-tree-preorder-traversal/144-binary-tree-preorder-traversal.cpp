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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        // preorder = root -> left -> right
         
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* curr = st.top();
            st.pop();
            ans.push_back(curr->val);       // root
            
            if(curr->right)                  // left
            {
                st.push(curr->right);
            } 
            if(curr->left)                 // right
            {
                st.push(curr->left);
            }
            
        }
        return ans;
    }
    
    
};
// Inorder Traversal 
// Root -> Left -> Right
// By using a single stack
