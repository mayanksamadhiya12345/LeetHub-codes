class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        
        int i=0;
        int j=1;
        ans.push_back(intervals[0]);
        while(j < n)
        {
            if(ans[i][1] < intervals[j][0])
            {
                ans.push_back(intervals[j]);
                i++;
            }
            else
            {
                ans[i][1] = max(ans[i][1],intervals[j][1]);
            }
            j++;
        }
        return ans;
    }
};