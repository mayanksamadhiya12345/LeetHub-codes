class Solution {
public:
    
    // knapsack problem
    int coinChange(vector<int>& num, int x) 
    {
        int n=num.size();
        vector<vector<int>> dp(n,vector<int> (x+1,0));

        // base case
        for(int i=0;i<=x;i++)
        {
            if(i%num[0]==0)
                dp[0][i] = i/num[0];
            else
                dp[0][i]=1e9;
        }

        for(int i=1;i<n;i++)
        {
            for(int target=0;target<=x;target++)
            {
                int not_pick = 0+dp[i-1][target];
                int pick = INT_MAX;
                if(target>=num[i])
                    pick = 1+dp[i][target-num[i]];

                dp[i][target]=min(pick,not_pick);
            }
        }
        int ans=dp[n-1][x];
        if(ans>=1e9)
            return -1;
        return ans;
    }
};