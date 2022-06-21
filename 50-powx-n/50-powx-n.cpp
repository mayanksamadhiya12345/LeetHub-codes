class Solution {
public:
    double myPow(double x, int n) 
    {
        double ans = 1;
        long temp = n;
        
        if(temp<0)
            temp = -temp;
        
        while(temp>0)
        {
            // odd
            if(temp%2==1)
            {
                ans = ans*x;
                temp--;
            }
            
            if(temp%2==0)
            {
                x = x*x;
                temp = temp/2;
            }
        }
        
        if(n<0)
        {
            ans = double(1)/ans;
        }
        return ans;
    }
};