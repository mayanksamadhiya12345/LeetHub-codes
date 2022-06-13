class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length())
            return false;
        
        // declared map for storing the occurance of characters
        map<char,int> mp;
        
        // storing the s string characters occurance
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        
        // now cheking the characters of t string in mp
        for(int i=0;i<t.length();i++)
        {
            // if character is not present then return false
            if(mp[t[i]] == 0)
                return false;
            
            // if value present in mp then minimize it occurance by 1
            else
                mp[t[i]]--;
        }
        return true;
    }
};