class Solution {
public:
    int find(int i,int j,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mx = INT_MIN;
        for(int idx=i;idx<=j;idx++)
        {
            int cost = (nums[i-1]*nums[idx]*nums[j+1]) + find(i,idx-1,nums,dp) + find(idx+1,j,nums,dp);
            mx = max(mx,cost);
        }
        
        return dp[i][j] = mx;
    }
    
    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        
        return find(1,n,nums,dp);
    }
};