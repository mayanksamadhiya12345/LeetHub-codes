class Solution {
public:
    bool solve(string &s1, string &s2) 
    {
        unordered_map<char, int> m1, m2;

        if(s1.size() != s2.size()) 
        {
            return false;
        }
        
        for(int i=0 ; i<s1.size() ; i++) 
        {
            if( m1[s1[i]] != m2[s2[i]])
                return false;
            
            m1[s1[i]] = i+1;
            m2[s2[i]] = i+1;
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> ans;
        
        for(auto &str : words) 
        {
            if(solve(str , pattern))
                ans.push_back(str);
        }  
        return ans;
    }
};