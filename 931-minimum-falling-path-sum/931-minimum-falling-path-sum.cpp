class Solution 
{
public:

    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        // base cases
        for(int j=0;j<n;j++)
        {
            dp[0][j] = matrix[0][j];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up = matrix[i][j] + dp[i-1][j];
                
                int up_left = matrix[i][j];
                if(j-1>=0)
                    up_left += dp[i-1][j-1];
                else
                    up_left += 1e9;
                
                
                int up_right = matrix[i][j];
                if(j+1<n)
                    up_right += dp[i-1][j+1];
                else
                    up_right += 1e9;
                
                dp[i][j] = min(up,min(up_left,up_right));
            }
        }
        
        
        int mn = INT_MAX;
        for(int j=0;j<n;j++)
        {
            mn = min(mn,dp[n-1][j]);
        }
        
        return mn;
    }
};