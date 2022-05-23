class Solution {
public:
    string removeDigit(string number, char digit) 
    {
        string res = "";
        
        // iterate over the number string
        for(int i=0;i<number.length();i++)
        {
            // if current value is equal to the given digit
            if(number[i] == digit)
            {
                // try to construct new string without current char
                string tmp = number.substr(0,i) + number.substr(i+1, number.size());
                
                // storing max
                res = max(res,tmp);
            }
        }
        return res;
    }
};