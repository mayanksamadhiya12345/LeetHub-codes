class Solution {
public:
    string longestPalindrome(string s) 
    {
        // size of string
        int n = s.length();
        
        // if string size is 1 then return string itself
        if(n==1)
            return s;
        
        // declared a 2D vector with value 0 of size nxn
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        
        // each single element is a palindrom string so make it 1
        // and if just next element also same with the previous element then make next element also 1
        for(int i=0;i<n;i++)
        {
            dp[i][i] = 1;                       // single element
            
            // after reaching last break it
            if(i==n-1)
                break;
            
            dp[i][i+1] = (s[i] == s[i+1]);      // if both elements are same
        }
        
        
        // after marking length1 and length2 digonals now check others
        // for palindromic substring it is necessary that boundary elements should be same 
        // and non bnoundary elements should be palindrom
        // s[i] == s[j]   Boundary Elements
        // dp[i+1] == dp[j-1]   Non Boundary Elements
        for(int i=n-3;i>=0;i--)
        {
            for(int j=i+2;j<n;j++)
            {
                dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
            }
        }
        
        int mx = INT_MIN;
        string mxPalindrom = "";
        
        // after filling our dp vector now check to Longest Palindromic Sunstring
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                // if current cell palindrom and its length is bigger then mx then update out LPS
                if(dp[i][j]==1 && j-i+1>mx)
                {
                    mx = j-i+1;
                    mxPalindrom = s.substr(i,j-i+1);
                }
            }
        }
        return mxPalindrom;
    }
};