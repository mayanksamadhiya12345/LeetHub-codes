class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> ans(nums.size());
        
        int l=0;
        int r=nums.size()-1;
        int i=nums.size()-1;
        
        while(l<=r)
        {
            if(abs(nums[l])<=nums[r])
            {
                ans[i--] = nums[r]*nums[r];
                r--;
            }
            else
            {
                ans[i--] = nums[l]*nums[l];
                l++;
            }
        }
        return ans;
    }
};