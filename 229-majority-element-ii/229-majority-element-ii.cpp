class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        // create the vector for storing the results
        vector<int> ans;
        int n=nums.size()/3;
        
        // create the map for calculating the frequency of each and every element
        unordered_map<int,int> freq;
        
        // counting the frequency
        for(int i=0; i<nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        
        for(auto i : freq)
        {
            // cheking the frequency and then append
            if(i.second>n)
                ans.push_back(i.first);
        }
        return ans;
    }
};