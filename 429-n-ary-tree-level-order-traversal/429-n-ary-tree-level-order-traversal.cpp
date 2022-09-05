/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans;
        if(root==NULL)                // if root is null then return empty vector
            return ans;
         
        queue<Node*> q;           // make a queue data structure for BFS traversal for finding the level order
        q.push(root);
       
        // BFS TRAVERSAL
        while(!q.empty())
        {
            vector<int> level;       // for storing the levels 
            int size = q.size();     // for storing the level size equal element
            
            for(int i=0;i<size;i++)
            {
                auto nod = q.front();      // takeout the front element
                q.pop();
                level.push_back(nod->val);      // after calling the current value push it to the level vector
                
                // store the next level nodes in queue (just one condition change in level order traversal code)
                for(auto it : nod->children)
                {
                    q.push(it);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};