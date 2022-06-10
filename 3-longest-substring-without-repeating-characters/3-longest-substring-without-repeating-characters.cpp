class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        // initially all the chars are unvisited (-1)
        vector<int> mp(256,-1);
        
        int len=0;
        int left=0;
        int right =0;
        int n=s.size();
        
        // till right pointer will not cross boundary
        while(right<n)
        {
            // if char already present in our map it means its repeatiting character 
            // so for avoiding this point our left to just next of curr char
            if(mp[s[right]]!=-1)
            {
                // if element is found in mp then move the left cursor by index+1
                left=max(mp[s[right]]+1,left);
            }
            
            mp[s[right]]=right;                  // storing the corresposding index for s[right] instaed of -1
            len=max(len,right-left+1);           // calculating the max length
            right++;
        }
        return len;
    }
};