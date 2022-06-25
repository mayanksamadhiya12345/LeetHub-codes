class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int mx = 0;
        set<int> st;
        int curr,val;
        for(int i:nums)
            st.insert(i);
        
        for(int i:nums)
        {
            if(!st.count(i-1))
            {
                curr = 1;
                val = i;
                
                while(st.count(val+1))
                {
                    curr++;
                    val++;
                }
            }
            mx = max(mx,curr);
        }
        return mx;
    }
};