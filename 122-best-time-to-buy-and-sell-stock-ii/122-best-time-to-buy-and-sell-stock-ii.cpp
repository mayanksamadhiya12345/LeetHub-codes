class Solution {
public:
    int find(int idx,int buy,vector<int>& prices,int n,vector<vector<int>>& dp)
    {
        // if i crossed the last element then i can not make any more profit further so return 0
        if(idx==n) return 0;
        
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        
        // now i am having two choices i can buy current stock or not so for that i declare a variable buy
        // if buy is 1 i can buy else sell
        
        int profit = 0;
        // buy
        if(buy==1)
        {
                         // buy                              // not buy
            profit = max(-prices[idx]+find(idx+1,0,prices,n,dp),0+find(idx+1,1,prices,n,dp));
        }
        
        // sell
        else
        {
                        // sell                              // not sell
            profit = max(prices[idx]+find(idx+1,1,prices,n,dp),0+find(idx+1,0,prices,n,dp));
        }
        
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return find(0,1,prices,n,dp);
    } 
};