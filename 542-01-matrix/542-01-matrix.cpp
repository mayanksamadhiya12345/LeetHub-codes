class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int m = mat.size(),n = mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;
                    q.push({i,j});
                }    
            }
        }
        
        int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newi = curr.first + dir[i][0];
                int newj = curr.second + dir[i][1];
                if(newi>=0 && newi<m && newj>=0 && newj<n)
                {
                    if(ans[newi][newj]>ans[curr.first][curr.second]+1)
                    {
                        ans[newi][newj] = ans[curr.first][curr.second]+1;
                        q.push({newi,newj});
                    }
                }
            }
        }
            
        return ans;
    }
};