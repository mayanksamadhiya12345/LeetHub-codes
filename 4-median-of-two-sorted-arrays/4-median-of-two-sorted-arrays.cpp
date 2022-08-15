class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        // computing the size of the arrys
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // we will take less size array first
        if(n2<n1)       //[2], []
            return findMedianSortedArrays(nums2, nums1);
        
        // assign low at first and high to end of arr1
        int low = 0;
        int high = n1;
        
        // binary search
        while(low<=high)
        {  
            // make cut1 and cut2 for partioning the arrays
            // here (n+m+1) is total length  
            int cut1 = (low+high)/2;                      // cut1 for the arr1
            int cut2 = (n1+n2+1)/2-cut1;                  // cut2 for the arr2
            
            
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1]; // right of arr1
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1]; // right of arr2
            
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];  // left of arr1
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];  // left of arr2
            
            // if all the left partitioned elements are the lesser than right then 
            // need to find the median
            if(l1<=r2 && l2<=r1)
            {
                // if length is even then median = (mid + mid + 1)/2
                if( (n1+n2) %2 ==0 )
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                // if odd
                else
                    return max(l1, l2);
            }
            // if l1 is bigger than need to shrink the arr1
            else if(l1>r2)
                high = cut1-1;
            else
                low = cut1+1;
        }
        return 0.0;
    }
};


//Binary search on first array to how many numbers to be selected from nums1?
// step-1 find cut1, cut2
// step-2 find l1, l2 & r1, r2
// step-3 if(l1<=r2 && l2<=r1)
//         (n1+n2)==even ? return max(l1,l2) + min (r1,r2)  / 2
//         else return max(l1, l2)