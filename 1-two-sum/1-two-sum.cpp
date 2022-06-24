class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            int y = target - nums[i];
            
            if(mp.find(y) != mp.end())
            {
                return {i,mp[y]};
            }
            
            mp[nums[i]] = i;
        }
        
        return {-1,-1};
    }
};