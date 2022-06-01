class Solution {
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        // iterating over the vector
       for(int i=1;i<nums.size();i++)
       {
           // ruuning sum
           nums[i]+=nums[i-1];
       }
       
       return nums;
    }
};