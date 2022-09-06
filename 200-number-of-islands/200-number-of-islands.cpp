class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size();           // rows
        int m=grid[0].size();        // col
        
        // if grid is empty it means no island is there
        if(n==0) return 0;
        
        int res=0;
        for(int i=0;i<n;i++)                         // iterate through the all cells
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')                  // if we get cell as value as 1 it means it is the starting of new islands so do res+1 for each new island
                {
                    dfs(grid,i,j,n,m);
                    res+=1;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>> &matrix,int x,int y,int r,int c)
    {
        //making boundaries 
        if(x<0 or y<0 or x>=r or y>=c or matrix[x][y]!='1')
        {
            return;
        }
        
        //mark as visited
        matrix[x][y]='2';                               // make currnt cell as 2 for get rid from from overlaping 
        
        //cheking all four directions
        dfs(matrix,x-1,y,r,c);      //top
        dfs(matrix,x+1,y,r,c);      //down
        dfs(matrix,x,y-1,r,c);      //left
        dfs(matrix,x,y+1,r,c);      //right
    }
};