class Solution {
public:
    int find(int idx,vector<int>& num,int target,vector<vector<int>>& dp)
    {
        // if i am at index 0 then i will check
        // my 0th value is making my target or not if it is then add those no. 
        // else return a big number so we can avoid that in min() function
        if(idx==0)
        {
            if(target%num[0]==0)
                return target/num[0];
            else
                return 1e9;
        }

        if(dp[idx][target]!=-1)
            return dp[idx][target];

        // not pick
        int not_pick = 0 + find(idx-1,num,target,dp);

        // pick
        int pick = INT_MAX;
        if(target>=num[idx])
            pick = 1 + find(idx,num,target-num[idx],dp);

        return dp[idx][target] = min(not_pick,pick);
    }
    
    // knapsack problem
    int coinChange(vector<int>& num, int x) 
    {
        int n=num.size();
        vector<vector<int>> dp(n,vector<int> (x+1,-1));
        int ans = find(n-1,num,x,dp);
        if(ans>=1e9)
            return -1;
        return ans;
    }
};