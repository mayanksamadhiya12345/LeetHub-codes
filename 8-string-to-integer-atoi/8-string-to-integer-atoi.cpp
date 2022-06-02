class Solution {
public:
    int myAtoi(string s) 
    {
        int n = s.size();
        int j = 0;              // it will point to the integer value ('0' to '9')
        
        // handling white spaces
        while(j<n && s[j]==' ')
            j++;
        
        if(j>=n)                         // if there are only white spaces in string then return 0
            return 0;
        
        
        // handling sign of the returnable int
        int sign = 1;
        if(s[j]=='-' or s[j]=='+')                   // check sign is '+' or '-' and according to that change the sign 
        {
            sign = (s[j]=='+') ? +1 : -1;
            j++;                                     // after changing the sign just move pointer by one
        }
        
        if(j>=n)
            return 0;                    // if there are only white spaces in string then return 0
        
        
        // counting the integer value for the given string
        int ans = 0;
        for(int i=j ; i<n && s[i]>='0' && s[i]<='9' ; i++)       // value should be between ('0' to '9') if not then return the previous ans
        {
            int tmp = s[i] - '0';
            
            // checking the overflow & underflow situation
            if(ans>INT_MAX/10 or (ans==INT_MAX/10 && tmp > INT_MAX % 10))
            {
                return (sign==1) ? INT_MAX : INT_MIN;
            }
            
            ans = (ans*10) + tmp;
        }
        
        return (ans*sign);
    }
};