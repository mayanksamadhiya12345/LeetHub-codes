class Solution {
public:
    int trap(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(mx<arr[i])
            {
                mx=arr[i];
                leftMax[i]=mx;
            }
            leftMax[i]=mx;
        }

        mx=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(mx<arr[i])
            {
                mx=arr[i];
                rightMax[i]=mx;
            }
            rightMax[i]=mx;
        }

        int res=0;
        for(int i=0;i<n;i++)
        {
            res = res + min(leftMax[i],rightMax[i])-arr[i];
        }

        return res;
    }
};