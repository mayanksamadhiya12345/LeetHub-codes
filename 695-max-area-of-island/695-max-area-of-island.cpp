class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows==0)
        {
            return 0;
        }
        int cols = grid[0].size();
        int maxArea = 0;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid[i][j]==1)
                    maxArea = max(maxArea, getArea(i, j, grid));
            }
        }
        
        return maxArea;
    }
                                  
    int getArea(int i, int j, vector<vector<int>>& grid)
     {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]<=0)
            return 0;
         
         //mark as visited
         grid[i][j] = -1;
         
         int leftArea = getArea(i, j-1, grid);
         int rightArea = getArea(i, j+1, grid);
         int upArea = getArea(i-1, j, grid);
         int downArea = getArea(i+1, j, grid);
         
         int totalArea = 1 + leftArea + rightArea + upArea + downArea;
         
        return totalArea;
     }
};