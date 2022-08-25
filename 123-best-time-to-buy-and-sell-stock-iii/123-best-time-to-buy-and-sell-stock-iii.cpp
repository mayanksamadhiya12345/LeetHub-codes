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
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return find(0,1,2,prices,n,dp);
    }
};