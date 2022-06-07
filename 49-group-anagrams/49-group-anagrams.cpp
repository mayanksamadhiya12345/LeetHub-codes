class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        // declaring an map that will store all angrams for a particular string
        // mp[ate] = [ate,eat,tea]   here (string = ate & vector<string> = [ate,eat,tea])
        
        map<string,vector<string>> mp;
        
        // start storing after sorting the string
        for(int i=0;i<strs.size();i++)
        {
            string tmp = strs[i];                         // extracting the current string value
            sort(strs[i].begin(),strs[i].end());          // sort for checking that we have already this string or not in our map  
            mp[strs[i]].push_back(tmp);                   // after cheking push current string value in corresponding sorted value
        }
        
        // final result value
        vector<vector<string>> res;
        
        // iterate over the map
        for(auto it : mp)
        {
            res.push_back(it.second);                      // storing the angrams for each unique string that we got after sort
        }
        return res;
    }
};
