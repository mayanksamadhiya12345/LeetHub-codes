class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> set; 
        set.insert(nums[0]);
        
        
        for (int i = 1; i < n; i++) {
            int ans = nums[i];
            
            nums[i] = ans + *set.rbegin();
        
            set.insert(nums[i]);
            
            if (set.size() > k) {
                set.erase(set.find(nums[i - k]));
            }
        }
        
        return nums.back();
    }
};