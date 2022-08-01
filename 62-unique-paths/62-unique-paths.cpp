class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m,vector<int> (n));
        
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    continue;
                else
                {
                    int left = 0;
                    if(j>0)
                        left = dp[i][j-1];
                    
                    int up = 0;
                    if(i>0)
                        up = dp[i-1][j];
                    
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
 
};