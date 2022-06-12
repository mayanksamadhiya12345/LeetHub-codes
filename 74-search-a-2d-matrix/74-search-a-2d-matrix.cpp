class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int x) 
    {
        int row = 0;
        int col = matrix[0].size()-1;
        
        while(col>=0 && row<matrix.size())
        {
            if(matrix[row][col]==x)
            {
                return true;
            }
            else if(matrix[row][col]<x)
            {
                row++;
            }
            else
            {
                col--;
            }
        }
        return false;
    }
};