// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int lower = 1, upper = n, mid;
        while(lower < upper) 
        {
            mid = lower + (upper - lower) / 2;
            
            // if i found bad then i will try to minimize my n
            if(!isBadVersion(mid)) 
                lower = mid + 1;  
            
            // if it is not bad then i need to minimize my range
            else 
                upper = mid;
        }
        
        return lower;  
    }
};