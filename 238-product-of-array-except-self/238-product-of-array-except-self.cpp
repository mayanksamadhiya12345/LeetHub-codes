class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans(n,0);
        int product=1;
        int zero=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                zero++;
            }
            else
            {
                product *= nums[i];
            }
        }
        
        if(zero>=2)
        {
            return ans;
        }
        
        for(int i=0;i<n;i++)
        {
            if(zero==1)
            {
                if(nums[i]==0)
                {
                    ans[i] = product;
                }
                else
                {
                    ans[i] = 0;
                }
            }
            else
            {
                ans[i] = product/nums[i];
            }
        }
        
        return ans;
    }
};