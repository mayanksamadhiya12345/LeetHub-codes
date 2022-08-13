class Solution {
public: 
    int lcs(string s,string t)
    {
        int n = s.length();
        int m = t.length();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        
        for(int j=0;j<=m;j++) prev[j]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                    curr[j]=1+prev[j-1];
                else
                    curr[j]=0+max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
    }
    
    int longestPalindromeSubseq(string s) 
    {
        string t = s;
        reverse(t.begin(),t.end());
        int n = lcs(s,t);
        return n;
    }
};