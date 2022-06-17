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
    int minCameraCover(TreeNode* root) 
    {
        // 0 : Camera Installed
        // 1 : Child don't want camera
        // -1: child wants to install camera
        
        // counter of no. of cameras
        int cnt = 0;
        
        int ans = find(root,cnt);                // DFS
        
        // if ans wants to insall camera then install a camera by increasing value of count
        // -1: child wants to install camera
        if(ans==-1)
            cnt++;
        
        return cnt;
    }
    
    int find(TreeNode* root,int& cnt)
    {
        // if root is null then no camera require so return 1
        // 1 : Child don't want camera
        if(root == NULL)
            return 1;
        
        // Going to left and right by DFS
        int left = find(root->left,cnt);
        int right = find(root->right,cnt);
        
        // -1: child wants to install camera
        if(left==-1 or right==-1)
        {
            cnt++;
            
            // after installing the camera made it 0 that signifies already installed
            return 0;
        }
        
        // 0 : Camera already Installed so return 1
        // 1 : Child don't want camera
        if(left==0 or right==0)
        {
            return 1;
        }
        
        // if no conditions works then return -1
        // -1: child wants to install camera
        return -1;
    }
};