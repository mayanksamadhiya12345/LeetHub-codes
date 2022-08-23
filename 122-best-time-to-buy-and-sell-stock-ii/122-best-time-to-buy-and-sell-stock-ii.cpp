class Solution {
public:   
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> ahead(2,0);
        
        // base case
        ahead[0] = ahead[1] = 0;                                    // also skip this portion as we declare our dp as 0
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                {
                    profit = max(-prices[idx]+ahead[0],0+ahead[1]);
                }
                else
                {
                    profit = max(prices[idx]+ahead[1],0+ahead[0]);
                }
                
                ahead[buy] = profit;
            }
        }
        
        return ahead[1];
    } 
};