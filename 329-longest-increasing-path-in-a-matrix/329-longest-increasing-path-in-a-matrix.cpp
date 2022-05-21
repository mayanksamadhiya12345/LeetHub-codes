class Solution {
private:
    
    //         {-1,0},
    // {0,-1},        {0,1},
    //         {1,0}
    int dirs[5] = {1,0,-1,0,1};
    
    bool isvalid(int& r,int& c,int R, int C)
    {
        // if we are not inside the the boundary then return false 
        if(r<0 || c<0 || r>=R || c>=C)
            return false;
        
        // else return true
        return true;
    }
    
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int r, int c)
    {
        // extracting the row and column size of the given matrix
        int R = matrix.size();
        int C = matrix[0].size();
        
        // if we have already computed the value for the cell then no need to compute again
        if(dp[r][c]!=0)
            return dp[r][c];
        
        // now according to condition we can move into 4 different directions 
        // so just go and compute the value in each direction
        for(int i=0;i<4;i++)
        {
            // according to current directions compute cells position
            int n_row = dirs[i]+r;
            int n_col = dirs[i+1]+c;
            
            // if our new direction is inside the boundary and the value is greater than the current one only then we will go for that
            if(isvalid(n_row,n_col,R,C) && matrix[n_row][n_col]>matrix[r][c])
                dp[r][c] = max(dp[r][c],1+helper(matrix,dp,n_row,n_col));                    // we are adding 1 here , because each cell length is 1 as we are taking this cell in our path so just add one
        }
        return dp[r][c];
    }
    
 public:   
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        // extracting the row and column size of the given matrix
        int row = matrix.size();
        int col = matrix[0].size();
        
        // created a new matrix and assign all value 0 initially
        vector<vector<int>> dp(row,vector<int>(col,0));
        int mx = 0;                                               // it will store the final max length
        
        // computing the max increasing length for each matrix cell
        // and returning the max one
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                // if cell is not computed
                if(dp[i][j]==0)
                {
                    // there is a helper function that will compute the maximum increasing length for cells
                    mx = max(mx,helper(matrix,dp,i,j));
                } 
            }
        }
        return mx+1;
    }
};