class Solution {
public:
    
    int uniquePaths(int m, int n) 
    {
        // delare a 2D vector with value -1 initially
        vector<vector<int>> dp(m,vector<int> (n));
        
        // start with base cases
        dp[0][0] = 1;
        
        // iteration
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                // base case
                if(i==0 && j==0)
                    dp[0][0] = 1;
                else
                {
                    int up = 0;
                    if(i>0)
                        up = dp[i-1][j];
                    
                    int left = 0;
                    if(j>0)
                        left = dp[i][j-1];
                    
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
  

};