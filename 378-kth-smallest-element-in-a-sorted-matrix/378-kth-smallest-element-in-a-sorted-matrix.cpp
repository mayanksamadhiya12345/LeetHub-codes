class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n=matrix.size();
        vector<int> dup;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dup.push_back(matrix[i][j]);
            }
        }
        
        sort(dup.begin(),dup.end());
        return dup[k-1];
    }
};