class Solution {
public:
    int find(int i,int j,string &s,string &t,vector<vector<int>>& dp)
    {
        if(i<0) return j+1;                // if first string exhausted then I need to perform remanining second string char insertions
        if(j<0) return i+1;                // if second string exhausted then I need to perform remanining first string char deletions
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        // if they both char are matched then i will do nothin just move my pointers
        if(s[i]==t[j]) return dp[i][j] = find(i-1,j-1,s,t,dp);
        
        // if they don't match so i have three options insert(i,j-1),delete(i-1,j),replace(i-1,j-1) and take min among them
        return dp[i][j] = 1 + min(find(i,j-1,s,t,dp),min(find(i-1,j,s,t,dp),find(i-1,j-1,s,t,dp)));
    }
    
    int minDistance(string s, string t) 
    {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        
        return find(n-1,m-1,s,t,dp);
    }
};