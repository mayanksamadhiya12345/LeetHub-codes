class Solution {
public:
    void merge(int low,int mid,int high,vector<int> &nums)
    {
        vector<int> temp;
        int i = low;
        int j = mid+1;
        int k = low;
        
        while(i<=mid && j<=high)
        {
            if(nums[i]<nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        
        while(i<=mid)
        {
            temp.push_back(nums[i++]);
        }
        
        while(j<=high)
        {
            temp.push_back(nums[j++]);
        }
        
        for(int i=low;i<=high;i++)
        {
            nums[i] = temp[i-low];
        }
    }
    
    void mergesort(int l, int r, vector<int> &nums)
    {
        if(l<r)
        {
            int mid = (l+r)/2;
            mergesort(l,mid,nums);
            mergesort(mid+1,r,nums);

            merge(l,mid,r,nums);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) 
    {
        mergesort(0,nums.size()-1,nums);
        return nums;
    }
};