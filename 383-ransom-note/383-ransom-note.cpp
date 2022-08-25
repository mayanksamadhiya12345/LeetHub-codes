class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        // declared map for storing the occurance of characters
        map<char,int> mp;
        
        if(ransomNote.length()>magazine.length())
            return false;
        
        // storing the magazine string characters occurance because it is super-set here
        for(int i=0;i<magazine.length();i++)
        {
            mp[magazine[i]]++;
        }
        
        // now cheking the characters of ransomNote string in mp (super-set)
        for(int i=0;i<ransomNote.length();i++)
        {
            // if value present in mp then minimize it occurance by 1
            if(mp[ransomNote[i]] != 0)
            {
                mp[ransomNote[i]]--;
            }
            
            // if character is not present then return false
            else
            {
                return false;
            }
        }
        return true;
    }
};