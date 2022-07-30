class Solution {
public:
    vector<string> permuted;
    void permute(string &s, int left, int right)
    {
        permuted.push_back(s);
        
        if (left == right)
        {
            return;
        }
        else
        {
            for (int i = left; i< right; i++)
            {
                // if curr value is digit then do nothing
                if (s[i] >= '0' && s[i] <= '9')
                    continue;
                
                if(isupper(s[i]))
                {
                    s[i]+=32;
                    permute(s, i+1, right);
                    s[i]-=32;    
                }
                else
                {
                    s[i]-=32;
                    permute(s, i+1, right);
                    s[i]+=32;
                } 
            }
        }
    }
        
    
    vector<string> letterCasePermutation(string s) 
    {
        permute(s, 0, s.size());
        return permuted;
    }
};