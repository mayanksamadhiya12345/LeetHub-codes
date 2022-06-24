class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        if(n==0)
            return ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long long a = nums[i]+nums[j];
                long long x = target - a;
                
                int st = j+1;
                int en = n-1;
                
                while(st<en)
                {
                    long long sum = nums[st]+nums[en];
                    
                    if(sum==x)
                    {
                        ans.push_back({nums[i],nums[j],nums[st],nums[en]});
                        
                        
                        // avoid duplication
                        while(st<en && nums[st]==nums[st+1]) st++;
                        while(st<en && nums[en]==nums[en-1]) en--;
                        st++;
                        en--;
                    }
                    else if(sum>x)
                        en--;
                    else
                        st++;
                }
                
                while(j+1<n && nums[j]==nums[j+1]) j++;
            }
            while(i+1 < n && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};