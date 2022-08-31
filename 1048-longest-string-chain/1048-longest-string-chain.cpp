class Solution {
public:
    
    bool check(string &s1,string &s2)
    {
        if(s1.size() != s2.size()+1) return false;
        
        int i=0;
        int j=0;
        
        while(i<s1.size())
        {
            if(s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        
        if(i==s1.size() && j==s2.size()) return true;
        return false;
    }
    
    // do compariosn based on size
    static bool compare(string s1, string s2)
    {
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& words) 
    {
        int n = words.size();
        sort(words.begin(),words.end(),compare);
        vector<int> dp(n,1);
        int mx  = 1;
        
        for(int idx=0;idx<n;idx++)
        {
            for(int prev=0;prev<idx;prev++)
            {
                if(check(words[idx],words[prev]) && 1+dp[prev]>dp[idx])
                {
                    dp[idx] = 1+dp[prev];
                }
            }
            mx = max(mx,dp[idx]);
        }
        
        return mx;
    }
};