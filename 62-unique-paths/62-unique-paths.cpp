class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<int> prev(n,0),curr(n,0);
        
        prev[0] = 1;
        
        for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    curr[j]=1;
                else
                {
                    int up = 0;
                    if(i-1 >= 0)
                        up += prev[j];
                    
                    int left = 0;
                    if(j-1 >= 0)
                        left += curr[j-1];
                    
                    curr[j] = left+up;
                }
            }
            prev = curr;
        }  
        return prev[n-1];
    }
 
};