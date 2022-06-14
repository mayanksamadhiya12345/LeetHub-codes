class Solution {
public:
    
    int helper(string word1, string word2,int m,int n,vector<vector<int>> &dp)
    {
        // if any value gets zero then return 0 because there is no lcs ahead
        if(m==0 or n==0)
            return 0;
        
        // if we have already calculated it then just return it
        if(dp[m][n] != -1)
            return dp[m][n];
        
        // here we check by using by [m-1][n-1] becuse strings are 0 base indexed
        // if both string characters are same then this will be the part of our LCS so add 1 and check for next one
        if(word1[m-1] == word2[n-1])
            return dp[m][n] = 1+helper(word1,word2,m-1,n-1,dp);
        
        // if not both are same then try to move pointer with respect to other and take maxone
        else
            return dp[m][n] = max(helper(word1,word2,m-1,n,dp),helper(word1,word2,m,n-1,dp));
    }
    
    int minDistance(string word1, string word2) 
    {
        // m + n - (2 * LCS)
        
        // size of word1 & word2
        int m = word1.size();
        int n = word2.size();
        
        // dp declaration
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        
        // build a function to calculte longest common subsequence
        int lcs = helper(word1,word2,m,n,dp);
        
        // return the value according to formula
        return m+n-(2*lcs);
    }
};