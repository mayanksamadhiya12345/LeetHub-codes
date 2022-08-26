class Solution {
public:
    int find(int idx,int buy,vector<int>& prices,int fee,vector<vector<int>>& dp)
    {
        if(idx==prices.size()) return 0;
        
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        
        if(buy==1) return dp[idx][buy] = max(-prices[idx]+find(idx+1,0,prices,fee,dp),0+find(idx+1,1,prices,fee,dp));
        else return dp[idx][buy] = max(prices[idx]-fee+find(idx+1,1,prices,fee,dp),0+find(idx+1,0,prices,fee,dp));
    }
    
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return find(0,1,prices,fee,dp);
    }
};