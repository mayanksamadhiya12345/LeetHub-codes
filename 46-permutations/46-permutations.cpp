class Solution {
public:
    void find(int idx,int n,vector<int>& nums,vector<vector<int>>& ans)
    {
        if(idx==n)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx;i<n;i++)
        {
            swap(nums[i],nums[idx]);
            find(idx+1,n,nums,ans);
            swap(nums[idx],nums[i]);
        }
        
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        int n=nums.size();
        find(0,n,nums,ans);
        return ans;
    }
};