class Solution {
public:
    int trap(vector<int>& arr) 
    {
        int n=arr.size();
        int l=0;
        int r=n-1;
        int leftMax=0;
        int rightMax=0;
        int res=0;

        while(l<=r)
        {
            if(arr[l]<=arr[r])
            {
                if(leftMax<=arr[l])
                    leftMax=arr[l];
                else
                    res = res + (leftMax-arr[l]);

                l++;
            }
            else
            {
                if(rightMax<=arr[r])
                    rightMax=arr[r];
                else
                    res = res + (rightMax-arr[r]);

                r--;
            }
        }
        return res;
    }
};