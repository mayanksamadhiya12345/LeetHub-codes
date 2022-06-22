class Solution 
{
public:
    int majorityElement(vector<int>& nums)
    {
        int majority = nums[0];
        int counter = 1;                 // cpunt of current element
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==majority)
                counter++;
            else
            {
                counter--;
                if(counter==0)
                {
                    majority=nums[i];
                    counter=1;
                }
            }
        }
        return majority;
    }
};