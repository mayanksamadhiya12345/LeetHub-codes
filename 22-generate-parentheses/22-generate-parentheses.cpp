class Solution {
public:
    void helper(vector<string>& res, int open, int close, string pair, int n)
    {
        if(pair.length()==n*2)
        { 
            res.push_back(pair);
            return;
        }
        
        if(open < n)
        {
            helper(res,open+1,close,pair+"(",n);
        }
        
        if(close < open)
        {
            helper(res,open,close+1,pair+")",n);
        }
        
        
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        helper(res,0,0,"",n);
        return res;
    }
};