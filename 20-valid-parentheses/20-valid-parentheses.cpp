class Solution {
public:
    bool isValid(string s) 
    {
        // creating the stack 
        stack<char> st;
        
        // iterating over the length of string
        for (int i=0; i<s.length(); i++) 
        {
            // if it is opening bracket then push it into the stack
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') 
            {
                st.push(s[i]);
            } 
            else 
            {
                // if stack is empty it means nothing for closing then return false immediate
                if (st.empty())  return false;
                
                // take top most element for comparison
                char t = st.top();
                
                // if it is closing small beracket
                if (s[i] == ')') 
                {
                    // not opening small bracketthen 
                    if (t != '(')   return false;
                    else st.pop();
                } 
                // smiliralar like small bracket
                else if (s[i] == ']') 
                {
                    if (t != '[')   return false;
                    else st.pop();
                } 
                else if (s[i] == '}') 
                {
                    if (t != '{')   return false;
                    else st.pop();
                } 
            } 
            
        }
        // check our stack is completely empty it means is there balance so return true else false
        if (st.empty())  return true;
        return false;
    }
};