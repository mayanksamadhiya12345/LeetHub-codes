class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        int n = arr.size();
        long long sum=0, mod = 1000000007;
        
        sort(arr.begin(), arr.end());
        map<long, long> mp;
        
        for(auto i:arr) mp[i]=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0 && mp.find(arr[i]/arr[j]) != mp.end())
                {
                    mp[arr[i]] += (mp[arr[j]]*(mp[arr[i]/arr[j]]))%mod;
                }
            }
            sum = (sum+mp[arr[i]])%mod;
        }
        return sum;
    }
};