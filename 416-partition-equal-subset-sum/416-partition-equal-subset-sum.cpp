class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum=0;
        for(auto it:nums)
            sum += it;
        
        vector<bool> prev(sum+1,false);
        vector<bool> curr(sum+1,false);
        
        prev[0]=true;
        curr[0]=true;
        
        if(nums[0]<=sum)
            prev[nums[0]]=true;
        
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            for(int tar=1;tar<=sum;tar++)
            {
                bool not_pick = prev[tar];
                bool pick = false;
                if(nums[i]<=tar)
                    pick = prev[tar-nums[i]];
                
                curr[tar] = not_pick or pick;
            }
            prev=curr;
        }
        
        for(int i=0;i<=sum;i++)
        {
            if(prev[i]==true)
            {
                int diff = abs((sum-i)-i);
                if(diff==0)
                    return true;
            }
        }
        return false;
    }
};