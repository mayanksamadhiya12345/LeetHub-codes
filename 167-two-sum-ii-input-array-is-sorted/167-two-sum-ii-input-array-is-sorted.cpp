class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left = 0;                    // left pointer
        int right = numbers.size()-1;    // right pointer
        
        // till both the pointers will not collide
        while(left<right)
        {
            // after getting our target value break it
            if(numbers[left]+numbers[right]==target)
            {
                return {left+1,right+1};
            }
            
            // if current sum is lower than target , so we need to maximize it , so move left pointer towards the right
            else if(numbers[left]+numbers[right]<target)
            {
                left++;
            }
            
            // if current sum is bigger than target so we need to minimize it , so move right pointer towards the left
            else
            {
                right--;
            }
        }
        
        return {-1,-1};
    }
};