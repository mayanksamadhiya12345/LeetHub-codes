class Solution {
public:
    int partitionString(string s) 
    {
        int n = s.length();
        int low = 0;
        int ans=0;
        
        map<char,int> mp;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                mp.clear();
                ans++;
            }
            mp[s[i]]=i;
        }
        
//         while(low<n)
//         {
//             if(mp.find(s[low]-'a')!=mp.end())
//             {
//                 mp.clear();
//                 ans++;
//             }
            
//             mp[s[low]-'a'] = low;
//             low++;
//         }
        
        if(!mp.empty()) ans++;
        return ans;
    }
};