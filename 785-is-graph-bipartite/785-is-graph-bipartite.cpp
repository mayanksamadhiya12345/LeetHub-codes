class Solution {
public:
    bool check(int node,vector<int>& color,vector<vector<int>>& graph)
    {
        queue<int> q;
        q.push(node);
        color[node] = 0;
        
        while(!q.empty())
        {
            int nod = q.front();
            q.pop();
            
            for(auto it : graph[nod])
            {
                if(color[it]==-1)
                {
                    color[it] = 1-color[nod];
                    q.push(it);
                }
                else
                {
                    if(color[it]==color[nod]) return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!check(i,color,graph)) return false;
            }
        }
        return true;
    }  
};
// using BFS