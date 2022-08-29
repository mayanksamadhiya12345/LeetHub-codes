class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        if(n==0)
        {
            return 0;
        }
        int m=grid[0].size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    bfs(grid,i,j,n,m);
                    res+=1;
                }
            }
        }
        return res;
    }
    void bfs(vector<vector<char>> &matrix,int x,int y,int r,int c)
    {
        //making boundaries 
        if(x<0 or y<0 or x>=r or y>=c or matrix[x][y]!='1')
        {
            return;
        }
        
        //mark as visited
        matrix[x][y]='2';
        
        //cheking all four directions
        bfs(matrix,x-1,y,r,c);      //top
        bfs(matrix,x+1,y,r,c);      //down
        bfs(matrix,x,y-1,r,c);      //left
        bfs(matrix,x,y+1,r,c);      //right
    }
};