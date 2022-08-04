class Solution {
public:
    int mirrorReflection(int p, int q) 
    {
        // gcd of p and q using inbuilt function
        int g = __gcd(p,q);
        // cout<<g<<endl;
        
        p=p/g;
        q=q/g;

        // logic as per the above explained pattern
        if(p==q) return 1;

        if(p%2==0)
        {
            return 2;
        }
        else
        {
            if(q%2==0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        return 0;
  	}
};