class Solution {
public:
    int mx;
    void dfs(int node,vector<int>& edges,vector<int>& vis,vector<int>& length,int curr_length)
    {
        if(!vis[node])
        {
            vis[node]=1;
            length[node]=curr_length;
            
            if(edges[node]!=-1)
            {
                dfs(edges[node],edges,vis,length,curr_length+1);
            }
            
            length[node]=-1;
        }
        else
        {
            if(length[node]!=-1)
            {
                mx = max(mx,curr_length-length[node]);
            }
        }
       
    }
    
    int longestCycle(vector<int>& edges) 
    {
        int V = edges.size();
        mx=-1;
        
        vector<int> vis(V,0);
        vector<int> length(V,-1);
        
        int curr_length=0;
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,edges,vis,length,curr_length);
            }
        }
        return mx;
    }
};