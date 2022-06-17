class Solution {
public:
    int find(int i,int j,vector<vector<int>>& nums,vector<vector<int>>& dp)
    {
        // edge cases
        if(i<0 or j<0 or nums[i][j]==1)
            return 0;
        
        if(i==0 && j==0)
            return 1;
        
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // I can move in to directions
        int up = find(i-1,j,nums,dp);
        int left = find(i,j-1,nums,dp);
        
        return dp[i][j] = up+left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();     // no. of rows
        int n = obstacleGrid[0].size();  // no. of columns
        
        // set all values as -1 for dp
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        // return the possible paths
        return find(m-1,n-1,obstacleGrid,dp);
    }
};