#define ll long long
class Solution {
public:
    int dp[105][105][30];
    ll min(ll a,ll b)
    {
        if(a<b)
            return a;
        else
            return b;
    }
    int helper(vector<int>& houses, vector<vector<int>>& cost, ll m, ll n, ll k,ll idx,ll last)
    {
        //base case;
        if(k<0)
        {
            return INT_MAX;
        }
        if(idx==m)
        {
            if(k==0)
                return 0;
            else
                return INT_MAX;
        }
        
        
        if(dp[k][idx][last]!=-1)
        {
            return dp[k][idx][last];
        }
        
        //if already colored
        if(houses[idx]!=0 && last==houses[idx] && last!=0)
        {
            return  dp[k][idx][last]=helper(houses,cost,m,n,k,idx+1,houses[idx]);
        }
        else if(houses[idx]!=0)
        {
            return  dp[k][idx][last]=helper(houses,cost,m,n,k-1,idx+1,houses[idx]);
        }
    
        //if not colored;
        ll ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(i+1!=last)
            {
                ans=min(ans,1LL*helper(houses,cost,m,n,k-1,idx+1,i+1)+cost[idx][i]);
            }
            else
            {
                ans=min(ans,1LL*helper(houses,cost,m,n,k,idx+1,i+1)+cost[idx][i]);
            }
        }
        return dp[k][idx][last]=ans;
        
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        memset(dp,-1,sizeof(dp));
        ll idx=0;
        ll k=target;
        ll last_color=0;
        ll ans= helper(houses,cost,m,n,target,idx,last_color);
        return (ans==INT_MAX)? -1 : ans;
        
    }
};