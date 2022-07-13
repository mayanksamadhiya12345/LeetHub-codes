class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length())
            return false;
        
        map<char,int> mp;
        
        for(auto i:s)
        {
            mp[i]++;
        }
        
        for(auto i:t)
        {
            if(mp[i]==0)
                return false;
            else
                mp[i]--;
        }
        return true;
    }
};