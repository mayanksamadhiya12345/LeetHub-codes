class Solution {
public:
    
    int uniquePaths(int m, int n) 
    {
        // delare a vector that will store prev row values
        vector<int> prev(n);
        
        // start with base cases
        prev[0] = 1;
        
        // iteration
        for(int i=0;i<m;i++)
        {
            // it will store the curr computing row value
            vector<int> curr(n);
            for(int j=0;j<n;j++)
            {
                // base case
                if(i==0 && j==0)
                    curr[j] = 1;
                else
                {
                    // move up so we need prev row , so use it
                    int up = 0;
                    if(i>0)
                        up = prev[j];
                    
                    // move left so we need curr row , so use it
                    int left = 0;
                    if(j>0)
                        left = curr[j-1];
                    
                    // store into curr
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        
        // return the last prev
        return prev[n-1];
    }
  

};