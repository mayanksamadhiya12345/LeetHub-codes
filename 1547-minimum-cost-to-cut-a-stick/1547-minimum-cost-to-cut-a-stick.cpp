class Solution {
public:
    int find(int i,int j,vector<int>& cuts,vector<vector<int>>& dp)
    {
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mn=1e9;
        for(int idx=i;idx<=j;idx++)
        {
            // curr stick length (cuts[j+1]-cuts[i-1]) and after this calculate the left part and right part also
            int cost = (cuts[j+1]-cuts[i-1]) + find(i,idx-1,cuts,dp) + find(idx+1,j,cuts,dp);
            mn = min(mn,cost);
        }
        return dp[i][j] = mn;
    }
    
    int minCost(int n, vector<int>& cuts) 
    {
        int c = cuts.size();
        cuts.push_back(n);                           // push the staick length at the end
        cuts.insert(cuts.begin(),0);                 // push 0 at the beggining
        sort(cuts.begin(),cuts.end());               // make sure to sort the arrau because after sorting we can easily run a loop to partition the array
        
        vector<vector<int>> dp(c+1,vector<int> (c+1,-1));
        
        return find(1,c,cuts,dp);
    }
};