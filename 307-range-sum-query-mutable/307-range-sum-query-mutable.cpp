class NumArray {
public:
    vector<int> dup;
    int sum=0;
    NumArray(vector<int>& nums) 
    {
        dup=nums;
        
        for(int i=0;i<nums.size();i++)
            sum += nums[i];
    }
    
    void update(int index, int val) 
    {
        sum -= dup[index];
        dup[index] = val;
        sum += dup[index];
    }
    
    int sumRange(int left, int right) 
    {
        int res=sum;
        for(int i=0;i<left;i++)
            res -= dup[i];
        
        for(int i=right+1;i<dup.size();i++)
            res -= dup[i];
        
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */