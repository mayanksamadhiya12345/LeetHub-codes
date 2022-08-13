class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> res;
        int n=words.size();
        int m=words[0].size(); // each word has the same length;
        int t = m*n;
        
        if(s.size() < t) return res;
        
        unordered_map<string, int> freq;
            
        for(auto it:words)
            freq[it]++;
        
        for(int i=0; i<=s.size()-t; i++)
        {
            unordered_map<string, int> mp = freq;
            
            int j;
            for(j=0; j<s.size(); j++)
            {
                string temp = s.substr(i+j*m, m); //create string of size m and starting index i+j*m
                
                if(mp[temp]==0)
                    break;
                else
                    mp[temp]--;
            }
            if(j==n) //check whether all word in words are in the string or not 
                res.push_back(i);
            
        }
        return res;
        
    }
};