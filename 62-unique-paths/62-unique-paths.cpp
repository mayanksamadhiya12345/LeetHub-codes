class Solution {
public:
    int find(int i,int j,vector<vector<int>>& dp)
    {
        // edge cases
        if(i==0 && j==0)
            return 1;
        
        if(i<0 or j<0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // I can move in to directions
        int up = find(i-1,j,dp);
        int left = find(i,j-1,dp);
        
        return dp[i][j] = up+left;
    }
    int uniquePaths(int m, int n) 
    {
        // delare a 2D vector with value -1 initially
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return find(m-1,n-1,dp);
    }
  

};