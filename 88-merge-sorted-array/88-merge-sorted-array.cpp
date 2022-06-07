class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        // in the question nums1 size is equal to the final nums size , and we need to return nums1 at the last
        // so we need to do changes in nums1
        // here we will start merging from behind 
        
        int i=m-1;                 // points to the given m
        int j=n-1;                 // points to the given n
        int k=m+n-1;               // final nums pointer with size (m+n-1)
        
        // till our pointer not get 0
        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])                       // if nums[i] is begger then take that value at the end , and move pointers behind 
                nums1[k--]=nums1[i--];
            else                                        // if nums[j] is begger then take that value at the end , and move pointers behind 
                nums1[k--]=nums2[j--];
        }
        
        // if i is not gets 0 then take it remainings values untill its get 0
        while(i>=0)
        {
            nums1[k--]=nums1[i--];
        }
        
        // if j is not gets 0 then take it remainings values untill its get 0
        while(j>=0)
        {
            nums1[k--]=nums2[j--];
        }
    }
};