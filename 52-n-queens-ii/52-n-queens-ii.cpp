class Solution {
public:
    void helper(int col, int n, vector<vector<string>>& ans , vector<string>& board, vector<int>& left, vector<int>& upperDigonal ,vector<int>& lowerDigonal)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(left[row]==0 && upperDigonal[row+col]==0 && lowerDigonal[col-row+n-1]==0)
            {
                board[row][col] = 'Q';
                left[row] = 1;
                upperDigonal[row+col] = 1;
                lowerDigonal[col-row+n-1] = 1;
                
                helper(col+1,n,ans,board,left,upperDigonal,lowerDigonal);
                
                board[row][col] = '.';
                left[row] = 0;
                upperDigonal[row+col] = 0;
                lowerDigonal[col-row+n-1] = 0;
            }
        }
    }
        
    int totalNQueens(int n) 
    {
        vector<vector<string>> ans;                 // created the data structure for storing the complete final ans
        vector<string> board(n);                    // store the current queue value
        string s(n,'.');                            // ['.','.','.','.'] (n=4)
        
        for(int i=0;i<n;i++)                        // initialize whole board as a empty string
        {
            board[i]=s;
        }
        
        // we are going from left to right
        // so we need to check only behind the current cell because all the cells after current cell will surely empty
        // we can not check for upper and lower direction for current cell also because each column and row has only one queen
        
        // using hashing for check the collision
        vector<int> left(n,0);                      // for cheking the left side we will maintaining an array that will tell which row has already taken for placing queen
        vector<int> upperDigonal(2*n-1,0);          // for checking the upper digonal we will maintaiing an array that will tell which upperdigonal has already taken
        vector<int> lowerDigonal(2*n-1,0);          // for checking the lower digonal we will maintaiing an array that will tell which lowerdigonal has already taken
        
        helper(0,n,ans,board,left,upperDigonal,lowerDigonal);  // called the function
        return ans.size();
    }
};