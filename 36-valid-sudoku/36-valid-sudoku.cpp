class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        // declaring three check arrays with zero initially
        int row[10][10]={0};
        int col[10][10]={0};
        int sub[10][10]={0};       
        
        // itearte over the rows
        for(int i=0;i<9;i++)
        {
            // iterate over the columns
            for(int j=0;j<9;j++)
            {
                // if there is nothing in box then go for next one without doing anyhting
                if(board[i][j]=='.')
                    continue;
                
                // cuurrent box value
                int num = board[i][j]-'0';
                
                // applying formula for cheking the value in sub box (3x3)
                int box = (i/3)*3 + (j/3);
                
                // if any one of the fiven condition repeated then it means it is not valid sudoku
                if(row[i][num] or col[num][j] or sub[box][num])
                    return false;
                
                // after all the stuff set current calculated values true from 0
                row[i][num] = true;
                col[num][j] = true;
                sub[box][num] = true;
            }  
        }
        return true;
    }
};