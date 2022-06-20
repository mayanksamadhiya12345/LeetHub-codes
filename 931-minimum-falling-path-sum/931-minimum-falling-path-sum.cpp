class Solution 
{
public:
    int help(int i,int j,vector<vector<int>> &matrix,vector<vector<int>>& dp)
    {
        // edge cases
        // if our column crosses the boundary
        if(j<0 or j>=matrix.size())
            return 1e9;                         // to avoid overflow i used 1e9 instead of INT_MAX
        
        // if we reached to our 0th row then return the value for of current column
        if(i==0)
            return matrix[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        // I can move in three directions
        int up = matrix[i][j] + help(i-1,j,matrix,dp);
        int up_left = matrix[i][j] + help(i-1,j-1,matrix,dp);
        int up_right = matrix[i][j] + help(i-1,j+1,matrix,dp);
        
        return dp[i][j] = min(up,min(up_left,up_right));                       // return the minimum out of them
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int mn = INT_MAX;
        for(int j=0;j<n;j++)
        {
            mn = min(mn,help(n-1,j,matrix,dp));
        }
        
        return mn;
    }
};