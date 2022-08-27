class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int prev_idx=idx-1;prev_idx>=-1;prev_idx--)
            {
                int not_take = 0 + dp[idx+1][prev_idx+1];
                int take = 0;
                if(prev_idx==-1 or nums[idx]>nums[prev_idx])
                    take = 1 + dp[idx+1][idx+1];

                dp[idx][prev_idx+1] = max(take,not_take);
             }
        }
        
        
        return dp[0][-1+1];
    }
};