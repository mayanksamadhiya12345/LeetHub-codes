class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        map<int,int> mp;
        for(auto it : arr) mp[it]++;
        
        priority_queue<int> pq;
        for(auto it : mp) pq.push(it.second);
        
        int sum = 0;
        int res = 0;
        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
            res++;
            if(sum>=(arr.size()/2))
                break;
        }
        
        return res;
    }
};