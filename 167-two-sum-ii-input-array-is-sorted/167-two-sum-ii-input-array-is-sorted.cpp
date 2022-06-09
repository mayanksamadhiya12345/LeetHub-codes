class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> res;                 // resulting vector
        int left = 0;                    // left pointer
        int right = numbers.size()-1;    // right pointer
        
        // till both the pointers will not collide
        while(left<right)
        {
            // after getting our target value 
            if(numbers[left]+numbers[right]==target)
            {
                // we are adding one because given array is 1 indexed and based on that we have to return the number indices
                res.push_back(left+1);
                res.push_back(right+1);
                break;
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
        
        return res;
    }
};