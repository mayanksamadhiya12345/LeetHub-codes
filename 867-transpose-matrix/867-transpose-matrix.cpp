class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) 
    {
        int row=matrix.size();
        int col=matrix[0].size();
        
        // declare the matrix ans[col][row] instead of ans[row][col] with value 0
        // because in res we are going to store result in transpose form (so just change the rows with col)
        vector<vector<int>> ans(col,vector<int> (row,0));
         
        // iterate over the matrix rows
        for(int i=0;i<row;i++)
        {
            // iterate over the columns for each row
            for(int j=0;j<col;j++)
            {
                // store values in new declared matrix in transpose form
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};