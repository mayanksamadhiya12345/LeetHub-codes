class Solution {
public:
    // kadane's algorithm
    int maxSubArray(vector<int>& nums) 
    {
        int current_sum=0;         // for storing the current sum
        int maxsum=INT_MIN;        // for storing the max sum
        
        // iterating over the nums for finding max sum
        for(int i=0;i<nums.size();i++)
        {
            current_sum=current_sum+nums[i];        // adding current value
            maxsum=max(maxsum,current_sum);         // finding max by using max function
            
            // if any point of time our curr_sum gets negative then make it 0 
            if(current_sum<0)
            {
                current_sum=0;
            }  
        }   
        return maxsum;
    }
};