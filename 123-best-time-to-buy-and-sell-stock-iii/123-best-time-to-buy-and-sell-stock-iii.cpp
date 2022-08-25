class Solution {
public:
    int find(int idx,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>>& dp)
    {
        // base case, either idx cross the boundary or cap reached to 0 we can not make any further profit
        if(idx==n or cap==0) return 0;
        
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        
        int profit=0;
        // can buy
        if(buy==1)
        {
                        // buy                                   // not buy
            return dp[idx][buy][cap] = max(-prices[idx]+find(idx+1,0,cap,prices,n,dp),0+find(idx+1,1,cap,prices,n,dp));
        }
        else
        {
                      // sell                                    // not sell
            return dp[idx][buy][cap] = max(prices[idx]+find(idx+1,1,cap-1,prices,n,dp),0+find(idx+1,0,cap,prices,n,dp));
        }
    }
    
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        // base cases, assign 0 
        // when cap==0 and idx and buy can anything
        // when idx==n and cap and buy can anything
        // there is no need to thse write cases because we already define our dp as 0
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    int profit=0;
                    // can buy
                    if(buy==1)
                    {
                                    // buy                                   // not buy
                        dp[idx][buy][cap] = max(-prices[idx]+dp[idx+1][0][cap],0+dp[idx+1][1][cap]);
                    }
                    else
                    {
                                  // sell                                    // not sell
                        dp[idx][buy][cap] = max(prices[idx]+dp[idx+1][1][cap-1],0+dp[idx+1][0][cap]);
                    }
                }
            }
        }
        
        return dp[0][1][2];
    }
};