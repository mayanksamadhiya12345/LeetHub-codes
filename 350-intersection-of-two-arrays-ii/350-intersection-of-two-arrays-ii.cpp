class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        map<int,int> mp;
        
        // just count the frequency of each elements in nums1
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]++;
        }
        
        // just check those elements in map those having frequency > 0 in nums2 
        for(int i=0;i<nums2.size();i++)
        {
            // means this element is present in nums1 & nums2 as well
            if(mp[nums2[i]]>0)
            {
                ans.push_back(nums2[i]); 
                mp[nums2[i]]--;
            }       
        }
        
        return ans;
    }
};

