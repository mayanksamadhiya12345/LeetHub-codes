class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int n = s.length();
        int m = t.length();
        
        vector<double> prev(m+1,0);
        vector<double> curr(m+1,0);
        
        // base case
        prev[0] = curr[0] = 1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1]) 
                    curr[j] = prev[j-1]+prev[j];              // i can match it and move j and i can also look for the nest match without moving j
                else 
                    curr[j] = prev[j];
            }
            prev = curr;
        }
    
        return (int)prev[m];
    }
};