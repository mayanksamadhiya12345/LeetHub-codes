class Solution {
public:    
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>> ahead(2,vector<int> (3,0));
        vector<vector<int>> curr(2,vector<int> (3,0));
        
        // base cases, assign 0 
        // when cap==0 and idx and buy can anything
        // when idx==n and cap and buy can anything
        // there is no need to thse write cases because we already define our dp as 0
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    // can buy
                    if(buy==1)
                    {
                                    // buy                                   // not buy
                        curr[buy][cap] = max(-prices[idx]+ahead[0][cap],0+ahead[1][cap]);
                    }
                    else
                    {
                                  // sell                                    // not sell
                        curr[buy][cap] = max(prices[idx]+ahead[1][cap-1],0+ahead[0][cap]);
                    }
                }
            }
            ahead = curr;
        }
        
        return ahead[1][2];
    }
};