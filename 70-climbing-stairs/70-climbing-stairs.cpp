// Using Tabulation (WithOut Optimizing Space Complexity)
class Solution 
{
public:
    int climbStairs(int n) 
    {
        if(n<=1)
        {
            return 1;
        }
        
        vector<int> dp(n+1,-1);
        
        if(dp[n] != -1)
            return dp[n];
        
        // start with base cases
        dp[0] = 1;
        dp[1] = 1;
        
        // and doing calculation till n
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};