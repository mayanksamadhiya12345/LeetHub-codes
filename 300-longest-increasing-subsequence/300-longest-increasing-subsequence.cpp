class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> dp(n,1);
        
        int mx = 1;
        for(int idx=0;idx<n;idx++)
        {
            for(int prev=0;prev<idx;prev++)
            {
                if(nums[prev]<nums[idx])
                {
                    dp[idx] = max(dp[idx],1+dp[prev]);
                }
            }
            mx = max(mx,dp[idx]);
        }
        return mx;
    }
};