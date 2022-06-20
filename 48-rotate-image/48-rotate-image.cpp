class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int row=matrix.size();
        int column=matrix[0].size();
        // Transpose
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                if(i<j)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }            
            }
        }
        
        // Reverse 
        for(int i=0;i<row;i++)
        {
            int st_col=0;
            int en_col=column-1;
            while(st_col<en_col)
            {
                swap(matrix[i][st_col],matrix[i][en_col]);
                st_col++;
                en_col--;
            }
        }     
    }
};