class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc)
    {
        hc.push_back(h);
        vc.push_back(w);
        int n=hc.size();
        int m=vc.size();
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        
        int max_h=hc[0];
        int max_v=vc[0];
        
        for(int i=1;i<n;i++)
        {
            int height=hc[i]-hc[i-1];
            max_h=max(max_h,height);
        }
        
        for(int j=1;j<m;j++)
        {
            int width=vc[j]-vc[j-1];
            max_v=max(max_v,width);
        }
        return (long)max_h*max_v % 1000000007;
    }
};