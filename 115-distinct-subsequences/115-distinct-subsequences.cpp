class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int n = s.length();
        int m = t.length();
        vector<vector<double>> dp(n+1,vector<double> (m+1,0));
        
        // base case
        // for every j=0 make i 1
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1]) 
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];              // i can match it and move j and i can also look for the nest match without moving j
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
    
        return (int)dp[n][m];
    }
};