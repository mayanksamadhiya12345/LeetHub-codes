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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        
        vector<vector<int>> ans;
        if(root==NULL)                // if root is null then return empty vector
            return ans;
         
        queue<TreeNode*> q;           // make a queue data structure for BFS traversal for finding the level order
        q.push(root);
       
        // BFS TRAVERSAL
        while(!q.empty())
        {
            vector<int> level;       // for storing the levels 
            int size = q.size();     // for storing the level size equal element
            
            for(int i=0;i<size;i++)
            {
                TreeNode* curr_node = q.front();      // takeout the front element
                q.pop();
                
                // left or right exist of current value then push it into the queue
                if(curr_node->left!=NULL)  q.push(curr_node->left);
                if(curr_node->right!=NULL) q.push(curr_node->right);
                
                level.push_back(curr_node->val);      // after calling the current value push it to the level vector
            }
            ans.push_back(level);
        }
        return ans;
    }
};

