class Solution {
public:
    int countSubstrings(string s) 
    {
        int n = s.size();           // size of string
        
        // left and right pointer for comparing  the characters for palindrom
        int l = 0;              
        int r = 0;
        int ans = 0;
        
        // now iterate over the string 
        for(int i=0;i<n;i++)
        {
            // ODD
            // calculate the palindrom for current char like (aaa) = a , aaa if i=1
            l = r = i;               // assign current value to the pointers
            
            // if both the pointers are inside the boundary
            while(l>=0 && r<n)
            {
                // palindrom 
                if(s[l]==s[r]) 
                    ans++;
                else 
                    break;
                
                // each time movie pointers for cheking next palin drom
                l--;
                r++;
            }
            
            
            // EVEN
            // now cheking palindrom for like (aa) = aa = 1
            // if my value is zero then we can not ccheck with it its previous (-1)
            if(i==0)
                continue;
            
            l = i-1; r = i;
            // if both the pointers are inside the boundary
            while(l>=0 && r<n)
            {
                // palindrom 
                if(s[l]==s[r]) 
                    ans++;
                else 
                    break;
                
                // each time movie pointers for cheking next palin drom
                l--;
                r++;
            }
        }
        return ans;
    }
};