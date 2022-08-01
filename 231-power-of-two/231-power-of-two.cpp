class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n==1 or n==2)
            return true;
        
        long long power=2;
        for(int i=1;i<=n;i++)
        {
            power = power*2;
            
            if(power==n)
                return true;
            else if(power>n)
                return false;
        }
        
        return false;
    }
};