class Solution {
public:
    // knapsack problem
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        
        // creating a dp that is having (coins size rows and amount size columns)
        // and assigning whole dp value INT_MAX initially because we need to return min value
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 1e5));          // taking +1 because we there is 0 based indexing
        
        // just start to fill our dp
        // iterate over coins
        for(int i=0;i<=n;i++)
        {
            // iterate over amount
            for(int j=0;j<=amount;j++)
            {
                // if my current amount is zero it means we need 0 coin to reach target
                if(j==0)
                    dp[i][j]=0;
                    
                // if my coin value is 0 then we need infinite coins to achieve target
                else if(i==0)
                    dp[i][j]=1e5;
                
                // if current coin value is bigger then the current amount then store previous row value
                else if(coins[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                
                // it will count the min coin numbers to achiveve current target value by using available coins
                // and store the min one that we can use for storing the amount value
                // we are using +1 for taking current coin and check for remaining amount (j-coins[i-1]) in same row(i)
                else
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
            }   
        }
        
        // if my last cell is having greater than 1e4 it means we can not reach the given amount by using given coins array
        // if it last cell is heving some finite value then return it
        return dp[n][amount] > 1e4 ? -1 : dp[n][amount];
    }
};