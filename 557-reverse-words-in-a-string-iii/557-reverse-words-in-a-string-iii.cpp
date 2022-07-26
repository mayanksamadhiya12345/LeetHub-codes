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
                reverse(tmp.begin(),tmp.end());
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
            reverse(tmp.begin(),tmp.end());
            if(ans=="")
                ans = tmp;
            else
                ans = ans+" "+tmp;
        }
            
        return ans;
    }
};