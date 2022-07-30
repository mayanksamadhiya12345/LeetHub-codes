class Solution {
public:
    void find(int i,int n,int k,vector<int>& ds,vector<vector<int>>& ans)
    {
        if(ds.size()>k)
            return;
        
        
        if(ds.size()==k)
        {
            ans.push_back(ds);
            return;
        }
        
        if(i>n)
            return;
        
        // pick
        ds.push_back(i);
        find(i+1,n,k,ds,ans);
        ds.pop_back();
        
        // not pick
        find(i+1,n,k,ds,ans);
        
        return;
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        find(1,n,k,ds,ans);
        return ans;
    }
};