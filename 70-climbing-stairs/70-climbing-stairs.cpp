// Using Tabulation (With Optimizing Space Complexity)
class Solution 
{
public:
    int climbStairs(int n) 
    {
        if(n<=1)
        {
            return 1;
        }
    
        // start with base cases
        int prev1 = 1;
        int prev2 = 1;
        int curr  = 0;
        
        // and doing calculation till n
        for(int i=1;i<n;i++)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};