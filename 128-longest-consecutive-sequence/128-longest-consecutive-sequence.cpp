class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        set<int> s;
        for(int i : nums)
        {
            s.insert(i);
        }
        
        int mx = 0;
        int val,curr;
        
        for(int i : nums)
        {
            if(!s.count(i-1))
            {
                val = 1;
                curr = i;
                
                while(s.count(curr+1))
                {
                    val++;
                    curr++;
                }
            }
            mx = max(mx,val);
        }
        return mx;
    }
};