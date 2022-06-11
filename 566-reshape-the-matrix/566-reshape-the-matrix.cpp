class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        int row = mat.size();
        int col = mat[0].size();
        
        // if matrix shape will not match with given shape then return mat itself
        if((row*col) != r*c)
            return mat;
        
        // declared a vector of given shape
        vector<vector<int>> res(r,vector<int> (c,0));
        
        // row & col for resutant vector
        int rw = 0;
        int cl = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                // filling the value from old to new one
                res[rw][cl] = mat[i][j];
                cl++;                        // each time change the column
                
                // if column reaches to the end again start with 0 with new row
                if(cl == c)
                {
                    cl = 0;
                    rw++;
                }
            }
        }
        return res;
    }
};