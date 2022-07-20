class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        // case 1: if the last element is smaller than target then return the length of vector
        // case 2: if first element of vector is greater than target then return 0
        if(nums[nums.size()-1]<target)
        {
            return nums.size();
        }     
        else if(nums[0]>target)
        {
            return 0;        
        }
          
        
        int low = 0;
        int high = nums.size()-1;
        int mid;
        int res=-1;
        
        // binary search
        while(low<=high)
        {
            mid = (low+high)/2;
            
            if(nums[mid] == target)   // found the element
            {
                return mid;
            }
            else if(nums[mid]>target)  // if nums[mid] is bigger then mid might be our result
            {
                high = mid-1;          // id nums[mid]>target its obvious that we need to search from 0 to mid-1
                res = mid;
            }
            else                       // if nums[mid]<target then mid+1 might be our answer
            {
                low = mid+1;
                res = mid+1;
            }  
        }
        return res; 
    }
};

// TC -> O(n+m)