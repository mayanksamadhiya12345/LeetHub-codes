class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> m;
        int n=nums.size();
        
        // itearte over the given nums
        for(int i=0;i<n;i++)
        {
            int x=nums[i];               // first number
            int y=target-x;              // deriving the second number for cheking that it is available or not
            
            // if it is present it means we have our target so just return the current index i and second number index that is m[y]
            if(m.find(y)!=m.end())
            {
                return {i,m[y]};
            }
            
            // every time store current nums value with respect to their index value
            m[nums[i]]=i;
        }
        
        // if we don't have any pair of target then return {-1,-1}
        return {-1,-1};
    }
};