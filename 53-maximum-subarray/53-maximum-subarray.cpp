class Solution {
public:
    // kadane's algorithm
    int maxSubArray(vector<int>& nums) 
    {
        int mx = INT_MIN;
        int curr = 0;
        
        for(auto x : nums)
        {
            curr += x;
            mx = max(mx,curr);
            
            if(curr < 0)
                curr = 0;
        }
        return mx;
    }
};