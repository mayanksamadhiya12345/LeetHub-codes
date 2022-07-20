class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        // making the starting and ending pointer
        int st = 0;
        int en = nums.size()-1;
        
        // till they did not cross
        while(st <= en)
        {
            // finding the mid value of indexs
            int mid = (st+en)/2;
            
            // of we found the target return index
            if(nums[mid] == target)
                return mid;
            
            // if our target is bigger it means we have to search in right part (st=mid+1 to en)
            else if(target>nums[mid])
            {
                st = mid+1;
            }
            
            // if our target is lesses it means we have to search in left part (st to en=mid-1)
            else if(target<nums[mid])
            {
                en = mid-1;
            }  
        }
        
        // if element does not found return -1
        return -1;
    }
};