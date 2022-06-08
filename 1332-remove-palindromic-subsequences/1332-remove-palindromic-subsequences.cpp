class Solution {
public:
    int removePalindromeSub(string s) 
    {
        // Approach : If given string is already Palindromic then we can remove it in one operation
        //          : If given string is not palindromic then we can remove it in two operations
        
        // so for soving the question we use the same logic that we use for check palindrom
        // if it is palindrom then return 1 else return 2
        
        int st = 0;                   // starting pointer
        int en = s.size()-1;          // endong pointer
        
        while(st < en)
        {
            // not palindrom then return 2
            if(s[st++] != s[en--])
                return 2;
        }
        
        // if palindrom return 1
        return 1;
    }
};