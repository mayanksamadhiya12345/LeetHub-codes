class Solution {
public:
    int find(vector<int>& nums)
    {
        int n = nums.size();
        
        // base cases
        int prev1 = nums[0];
        int prev2 = 0;
        int curr = 0;
        
        for(int i=1;i<n;i++)
        {
            int pick = nums[i];
            if(i > 1)
                pick += prev2;
            
            int notpick = 0 + prev1;
            
            curr = max(pick,notpick);
            
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        
        if(n==1)
            return nums[0];
        
        // houses are in circle and two adjacent houses can not be rob at same night
        // it means 1st and last house can not be in the same night rob
        // so first seprate them 
        vector<int> temp1,temp2;
        
        for(int i=0;i<n;i++)
        {
            // temp1 (storing all values except first)
            if(i != 0)
                temp1.push_back(nums[i]);
            
            // temo2 (storing all the values except last)
            if(i != n-1)
                temp2.push_back(nums[i]);
        }
        
        return max(find(temp1),find(temp2));
    }
};