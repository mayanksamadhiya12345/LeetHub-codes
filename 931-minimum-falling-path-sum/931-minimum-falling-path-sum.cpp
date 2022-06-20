class Solution 
{
public:

    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<int> prev(n,0) , curr(n,0);
        
        // base cases
        for(int j=0;j<n;j++)
        {
            prev[j] = matrix[0][j];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up = matrix[i][j] + prev[j];
                
                int up_left = matrix[i][j];
                if(j-1>=0)
                    up_left += prev[j-1];
                else
                    up_left += 1e9;
                
                
                int up_right = matrix[i][j];
                if(j+1<n)
                    up_right += prev[j+1];
                else
                    up_right += 1e9;
                
                curr[j] = min(up,min(up_left,up_right));
            }
            prev = curr;
        }
        
        
        int mn = INT_MAX;
        for(int j=0;j<n;j++)
        {
            mn = min(mn,prev[j]);
        }
        
        return mn;
    }
};