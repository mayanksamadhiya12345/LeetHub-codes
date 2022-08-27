class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int prev_idx=idx-1;prev_idx>=-1;prev_idx--)
            {
                int not_take = 0 + prev[prev_idx+1];
                int take = 0;
                if(prev_idx==-1 or nums[idx]>nums[prev_idx])
                    take = 1 + prev[idx+1];

                curr[prev_idx+1] = max(take,not_take);
             }
             prev = curr;
        }
        
        
        return prev[-1+1];
    }
};