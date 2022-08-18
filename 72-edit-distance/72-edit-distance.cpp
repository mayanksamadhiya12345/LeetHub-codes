class Solution {
public:
    int minDistance(string s, string t) 
    {
        int n = s.length();
        int m = t.length();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        
        // i don't need column , i just need row
        for(int j=0;j<=m;j++) prev[j]=j;
        
        for(int i=1;i<=n;i++)
        {
            curr[0]=i;
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1]) curr[j] = 0 + prev[j-1];
                else curr[j] = 1 + min(curr[j-1],min(prev[j],prev[j-1]));
            }
            prev=curr;
        }
        
        return prev[m];
    }
};