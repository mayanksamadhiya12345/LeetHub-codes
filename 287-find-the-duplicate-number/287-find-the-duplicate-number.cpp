class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mp[i]>1)
            {
                return i;
            }
        }
        return 0;
    }
};