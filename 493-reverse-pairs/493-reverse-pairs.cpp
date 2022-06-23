class Solution {
public:
    int merge(vector<int>& nums, int temp[], int left, int mid,int right)
    {
        int i, j, k;
        int count = 0;
 
        i = left;   /* i is index for left subarray*/
        j = mid+1;  /* j is index for right subarray*/
        k = left;   /* k is index for resultant merged subarray*/
       
        //counting reverse pairs
        while(i<=mid and j<=right)
        {
            if((double)(nums[i])<=(double)2*nums[j])
            {   
                i++;
            }
            else
            {
                count += mid-i+1; 
                j++;
            }
        }
     
        //merging
        i = left; /* i is index for left subarray*/
        j = mid+1; /* j is index for right subarray*/
        
        while ((i <= mid) && (j <= right)) 
        {
            if (nums[i] <= nums[j]) 
            {
                temp[k++] = nums[i++];
            }
            else 
            {   
                temp[k++] = nums[j++];
            }
        }
 
        /* Copy the remaining elements of left subarray
          (if there are any) to temp*/
        while (i <= mid)
            temp[k++] = nums[i++];
 
        /* Copy the remaining elements of right subarray
          (if there are any) to temp*/
        while (j <= right)
            temp[k++] = nums[j++];
 
        /*Copy back the merged elements to original array*/
        for (i = left; i <= right; i++)
            nums[i] = temp[i];
 
        return count;
    }

    int mergeSort(vector<int>& nums, int temp[],int left, int right)
    {
        int count = 0;
        if (right > left) 
        {
            /* Divide the array into two parts */
            int mid = (right + left) / 2; 
  
            count += mergeSort(nums, temp, left, mid);
            count += mergeSort(nums, temp, mid + 1, right);
 
            /*Merge the two parts*/
            count += merge(nums, temp, left, mid, right);
        }
        return count;
    }


    int reversePairs(vector<int>& nums) 
    {
        int temp[nums.size()];
        return mergeSort(nums, temp, 0, nums.size()-1);    
    }
};