class Solution {
public:
    void helper(vector<string>& res, int open, int close, string pair, int n)
    {
        // if our pair size reach to the double of given number , it means we have reached to our combination
        if(pair.length()==n*2)
        { 
            res.push_back(pair);
            return;
        }
        
        // if open parenthesis value is under n then add '(' , and increase open by 1
        if(open < n)
        {
            helper(res,open+1,close,pair+"(",n);
        }
        
        // we can add close parenthesis only and only when, our close is under open
        // because we have to make well formed parenthesis
        if(close < open)
        {
            helper(res,open,close+1,pair+")",n);
        }
        
        
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;            // it will store final result
        helper(res,0,0,"",n);          // recursion
        return res;                    // returning
    }
};
