class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int ans=0;
        
        // iterate over the 32 bit integer
        for(int i=0;i<=31;i++)
        {
            // start counting 1 from behind
            // if it gives not zero value it means we can count that as 1
            // and after taking that 1 just update our number by using (n/2)
            if(n%2 != 0)
            {
                ans++;   
            }
            n = n/2;
        }
        
        return ans;
    }
};