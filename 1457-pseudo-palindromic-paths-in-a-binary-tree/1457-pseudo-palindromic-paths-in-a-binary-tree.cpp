class Solution {
public:
    int count = 0;
    void dfs(TreeNode* root, vector<int> vt)
    {
        if(root == NULL) return;
        
        // increment the count of the curr node's val
        vt[root -> val]++;
        
        // if we reached the leaf node then count the no. of odd frequency, if odd frequency is more than 1 then palindrome is not possible
        
        if(root -> left == NULL && root -> right == NULL)
        {
            int odd_count = 0;
            
            for(auto x : vt)
            {
                if(x % 2) odd_count++;
            }
            
            if(odd_count <= 1) count++;
            return;
        }
        
        // call for left subtree
        dfs(root -> left, vt);
        
        // call for right subtree
        dfs(root -> right, vt);
    }

    
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        vector<int> vt(10, 0);
        dfs(root, vt);     
        return count;
    }
};