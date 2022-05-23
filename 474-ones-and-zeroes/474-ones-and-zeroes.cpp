class Solution 
{
public:
    
    //function for count 0s and 1s 
    vector<int> count(string s)
    {
        
        vector<int> cnt(2);
        for(auto it: s)
        {
            it=='0' ? cnt[0]++ : cnt[1]++;
        }
        return cnt;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        //define 2D vector of zeros+1 rows and ones+1 columns
        vector<vector<int>> dp(m+1, (vector<int> (n+1, 0)));
        
        //iterate over strs and get string s
        for(string s:strs)
        {
            //count 0s an 1s in string s
            vector<int> cnt = count(s);
            
            //zero -> m-count[0]  ---- 0
            //one -> n-count[1] ---- 0
            for(int zero=m; zero>=cnt[0]; zero--)
            {
                for(int one=n; one>=cnt[1]; one--)
                {
                    dp[zero][one] = max(1+dp[zero-cnt[0]][one-cnt[1]], dp[zero][one]);
                }
            }
        }
        return dp[m][n];
    }
};