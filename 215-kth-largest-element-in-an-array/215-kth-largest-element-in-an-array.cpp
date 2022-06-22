class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());             // Sort the values in increasing order  [1,2,3,4,5,6]
        
        // return nums.szie()-k because we need Greater Kth eleemnt that lies behind
        return nums[nums.size()-k];
    }
};