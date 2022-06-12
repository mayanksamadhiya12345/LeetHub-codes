class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        //finding subarray(with unique elements) with maximum score
        int score = -1;
        
        vector<int> map(1e4+1, -1); //stores index of the elements
        
        
        //make prefix sum to get score
        vector<int> prefixSum;
        int sum = 0;
        for(int it: nums)
        {
            sum+= it;
            prefixSum.push_back(sum);
        }
        
        //finding subarray(with unique elements) with maximum score
        int start = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(map[nums[i]] != -1)
            { 
                //if element repeats in nums, update start
                start = max(start, map[nums[i]]+1);
            }
            
            map[nums[i]] = i;   //update index
            
            //get max score
            int left = (start==0)? 0: prefixSum[start-1];
            
            score = max(score, prefixSum[i]- left);  
        }
        
        return score;
    }
};