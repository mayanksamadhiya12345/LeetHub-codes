class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<int> ahead(2,0);
        vector<int> curr(2,0);
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy==1) curr[buy] = max(-prices[idx]+ahead[0],0+ahead[1]);
                else curr[buy] = max(prices[idx]-fee+ahead[1],0+ahead[0]);
            }
            ahead=curr;
        }
        return ahead[1];
    }
};