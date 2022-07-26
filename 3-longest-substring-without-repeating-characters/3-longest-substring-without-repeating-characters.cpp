class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> mp(256,-1);
        
        int l=0;
        int r=0;
        int length=0;
        int n=s.length();
        
        while(r<n)
        {
            if(mp[s[r]] != -1)
                l = max(l,mp[s[r]]+1);
            
            mp[s[r]] = r;
            length = max(length,r-l+1);
            r++;
        }
        return length;
    }
};