// Using Dynamic Programming
// Tabulization (Optimized Space Complexity)

class Solution 
{
public:
    int fib(int n)
    {
        if(n<=1)
            return n;
        
        int prev2 = 0;
        int prev1 = 1;
        int curr  = 0;
        
        for(int i=2;i<=n;i++)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};

// TC : O(n)                  // for computing values from 0 to n
// SC : O(1)                  