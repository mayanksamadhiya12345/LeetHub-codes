class Solution {
public:
    void solve(int col,int n,vector<string> &board,vector<vector<string>> &ans,vector<int> &left,vector<int> &upperDigonal,vector<int> &lowerDigonal)
    {
        // if we reached to the boundry then return the board into the ans
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        // cheking for each row of given col
        for(int row=0;row<n;row++)
        {
            // if our hash value is 0 it means we can place a queen over there there is no collison (in left , upper & lower digonal)
            if(left[row]==0 && upperDigonal[row+col]==0 && lowerDigonal[n-1+col-row]==0)
            {
                board[row][col]='Q';                 // store Q afetr checking all three condition
                
                // make the hashmap from 0 to 1 after considering current position as a queen
                left[row]=1; 
                upperDigonal[row+col]=1;
                lowerDigonal[n-1+col-row]=1;
                
                // after filling current column successfully go to next one
                solve(col+1,n,board,ans,left,upperDigonal,lowerDigonal);
                
                // BackTracking
                board[row][col]='.';
                left[row]=0;
                upperDigonal[row+col]=0;
                lowerDigonal[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        // we have to check three conditions
        // 1. each row has one queen
        // 2. each column has one queen
        // 3. any queen will not attack on any other queen (queen can go in 8 directions)
        
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
        
        solve(0,n,board,ans,left,upperDigonal,lowerDigonal);  // called the function
        return ans;
    }
};