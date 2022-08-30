class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        int lastidx=0;
        
        sort(nums.begin(),nums.end());                   // for changing the problem into longest increasing subset
        int mx = 1;
        for(int idx=0;idx<n;idx++)
        {
            hash[idx] = idx;
            for(int prev=0;prev<idx;prev++)
            {
                if(nums[idx]%nums[prev]==0 && (1+dp[prev]>dp[idx]))
                {
                    dp[idx] = 1+dp[prev];
                    hash[idx] = prev;
                }
            }
            if(dp[idx]>mx)
            {
                mx = dp[idx];
                lastidx = idx;
            }
        }
        
        vector<int> ans;
        ans.push_back(nums[lastidx]);
        
        while(hash[lastidx]!=lastidx)
        {
            lastidx = hash[lastidx];
            ans.push_back(nums[lastidx]);
        }
        
        reverse(ans.begin(),ans.end());
        cout<<mx;
        return ans;
    }
};