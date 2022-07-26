class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int l = 0;                       // left pointer
        int r = s.size()-1;              // right pointer
        
        // till left and right pointer do not cross to each other
        while(l<=r)
        {
            // swapping the left and right values
            char tmp = s[r];
            s[r] = s[l];
            s[l] = tmp;
            
            // moving the Pointers
            l++;
            r--;
        }
    }
};