class Solution {
public:
    bool hasAllCodes(string s, int k)
    {
        unordered_set<string> us;
        int n  = s.length();
        string ans;
        
        for(int i=0;i<=n-k;i++)
        {
            ans = s.substr(i,k);
            us.insert(ans);
            
            if(us.size()==pow(2,k))
            {
                return true;
            }
        }
        return false;
    }
};