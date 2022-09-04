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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        // we will use the multiset here because at a level there can be same value or not be same also
        // (node,vertical,level)
        map<int,map<int,multiset<int>>> ds;
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            // taking out the front of the queue and than pop that
            auto a = q.front();
            q.pop();
            
            TreeNode* p = a.first;          // taking out the node
            int x = a.second.first;         // taking out the vertical number
            int y = a.second.second;        // taking out the level number
            
            ds[x][y].insert(p->val);        // insert all this data into our map (node,ver,lev)
            
            // if there is a left node then we will move on left by decreasing of 1 in ver and increasing of 1 in lev
            if(p->left!=NULL)
                q.push({p->left,{x-1,y+1}});
            
            // if there is a right node then we will move on right by increasing of 1 in ver and increasing of 1 in lev
            if(p->right!=NULL)
                q.push({p->right,{x+1,y+1}});
        }
        // from here i will get my map <data,vertical_level,level> format
        
        // for storing the last answer
        vector<vector<int>> ans;
        for(auto p : ds)           // iterate over the whole map
        {
            vector<int> col;       // make a temp vector for storing the each vertical order
            
            for(auto q : p.second) // iterate over the (ver,lev)
            {
                // here we will take each level by q.second.begin(),q.second.end() for each vertical order from behind
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};