class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n=nums.size();
        if(n==0)
            return {-1,-1};
        
        int l=0;
        int r=n-1;
        
        vector<int> ans(2,-1);
        // finding the first occurance
        while(l<=r)
        {
            int m=(l+r)/2;
            
            if(nums[m]>target)
            {
                r=m-1;
            }
            else if(nums[m]<target)
            {
                l=m+1;
            }
            else
            {
                if(m==l or nums[m]!=nums[m-1])
                {
                    ans[0]=m;
                    break;
                }
                else
                {
                    ans[0]=m-1;
                    r=m-1;
                }
            }
        }
        
        // finding the second occurance
        l=0;
        r=n-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            
            if(nums[m]>target)
            {
                r=m-1;
            }
            else if(nums[m]<target)
            {
                l=m+1;
            }
            else
            {
                if(m==r or nums[m]!=nums[m+1])
                {
                    ans[1]=m;
                    break;
                }
                else
                {
                    ans[1]=m+1;
                    l=m+1;
                }
            }
        }
        return ans;
    }
};