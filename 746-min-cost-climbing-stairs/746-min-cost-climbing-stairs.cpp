class Solution {
public:
    int find(vector<int>& cost,int i,vector<int>& dp)
    {
        if(i<=1)
            return dp[i]=cost[i];
        
        if(dp[i]!=-1)
            return dp[i];
        
        int pick = find(cost,i-1,dp);       // 1 move
        int notpick = find(cost,i-2,dp);    // 2 move
        
        return dp[i] = cost[i]+min(pick,notpick);
    }
    
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(find(cost,n-1,dp),find(cost,n-2,dp));
    }
};