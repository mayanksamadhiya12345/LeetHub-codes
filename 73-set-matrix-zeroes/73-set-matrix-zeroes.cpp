class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        // cheking for first column
        int col0 = 1;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++) 
        {
            // if first column element is zerio it will distruph that row and col
            if (matrix[i][0] == 0) 
            {
                col0 = 0;
            }
            // we will start from second column
            for (int j = 1; j < cols; j++)
            {
                // check eleemnt is zero or not
                if (matrix[i][j] == 0)
                {
                 //  left most     top most 
                     matrix[i][0] = matrix[0][j] = 0;
                }     
            }       
        }
    
        // back iteration
        for (int i = rows - 1; i >= 0; i--) 
        {
            for (int j = cols - 1; j >= 1; j--)
            {
                // if any from top or left most is zero then make that element zero
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }      
            } 

            // first col element is zero then make that zero+-
            if (col0 == 0)
            {
                matrix[i][0] = 0;
            }
        }
        
    }
};