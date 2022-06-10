class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = INT_MIN;             // it will store max profit
        int min_price = INT_MAX;          // it will store min price at Ith day
        
        // itearte over all prices
        for(int i=0;i<prices.size();i++)
        {
            min_price = min(min_price,prices[i]);                        // finding min price
            profit    = max(profit, prices[i]-min_price);                // max profit
        }
        return profit;
    }
    
};