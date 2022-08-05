class Solution {
public:
    
    // knapsack problem
    int coinChange(vector<int>& num, int x) 
    {
        int n=num.size();
        vector<int> prev(x+1,0);
        vector<int> curr(x+1,0);

        // base case
        for(int i=0;i<=x;i++)
        {
            if(i%num[0]==0)
                prev[i] = i/num[0];
            else
                prev[i]=1e9;
        }

        for(int i=1;i<n;i++)
        {
            for(int target=0;target<=x;target++)
            {
                int not_pick = 0+prev[target];
                int pick = INT_MAX;
                if(target>=num[i])
                    pick = 1+curr[target-num[i]];

                curr[target]=min(pick,not_pick);
            }
            prev=curr;
        }
        int ans=prev[x];
        if(ans>=1e9)
            return -1;
        return ans;
    }
};