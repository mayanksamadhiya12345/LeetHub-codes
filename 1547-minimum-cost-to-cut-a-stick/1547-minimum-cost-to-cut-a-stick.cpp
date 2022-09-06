class Solution {
public:
    int minCost(int n, vector<int>& cuts) 
    {
        int c = cuts.size();
        cuts.push_back(n);                           // push the staick length at the end
        cuts.insert(cuts.begin(),0);                 // push 0 at the beggining
        sort(cuts.begin(),cuts.end());               // make sure to sort the arrau because after sorting we can easily run a loop to partition the array
        
        vector<vector<int>> dp(c+2,vector<int> (c+2,0));
        
        for(int i=c;i>=1;i--)
        {
            for(int j=1;j<=c;j++)
            {
                if(i>j) continue;          // base case (if there is no stick no need to cut it further)
                
                int mn = INT_MAX;
                for(int idx=i;idx<=j;idx++)
                {
                    // curr stick length (cuts[j+1]-cuts[i-1]) and after this calculate the left part and right part also
                    int cost = (cuts[j+1]-cuts[i-1]) + dp[i][idx-1] + dp[idx+1][j];
                    mn = min(mn,cost);
                }
                dp[i][j] = mn;
            }
        }
        
        return dp[1][c];
    }
};