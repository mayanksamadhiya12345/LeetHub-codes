class Solution {
public:
    string reverseWords(string s) 
    {
        string ans ="";
        string tmp ="";
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                int l = 0;                       // left pointer
                int r = tmp.size()-1;                     // right pointer

                // till left and right pointer do not cross to each other
                while(l<=r)
                {
                    // swapping the left and right values
                    char temp = tmp[r];
                    tmp[r] = tmp[l];
                    tmp[l] = temp;

                    // moving the Pointers
                    l++;
                    r--;
                }
                
                if(ans=="")
                {
                    ans = tmp;
                }
                else
                {
                    ans = ans+" "+tmp;
                }
                
                tmp = "";
            }
            else
            {
                tmp += s[i];
            }
        }
        if(tmp!=" ")
        {
            int l = 0;                       // left pointer
            int r = tmp.size()-1;                     // right pointer

            // till left and right pointer do not cross to each other
            while(l<=r)
            {
                // swapping the left and right values
                char temp = tmp[r];
                tmp[r] = tmp[l];
                tmp[l] = temp;

                // moving the Pointers
                l++;
                r--;
            }

            if(ans=="")
            {
                ans = tmp;
            }
            else
            {
                ans = ans+" "+tmp;
            } 
        }
            
        return ans;
    }
};