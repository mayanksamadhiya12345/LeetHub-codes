class Solution {
public:
    int firstUniqChar(string s) 
    {
        // declared map for storing the occurance of character
        map<char,int> mp;
        
        // storing occurance of characters
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        
        // check first non repeating character
        for(int i=0;i<s.size();i++)
        {
            if(mp[s[i]] == 1)          // if its count 1 then return it
                return i;
        }
        
        // if there is no unique char then return -1
        return -1;
    }
};
