class Solution {
public:
    
    // do compariosn based on size
    static bool compare(string s1, string s2)
    {
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& words) 
    {
        //it will store predecessor word and their chain size
        unordered_map<string, int> dp; 
        
        //sort(words.begin(), words.end() based of the word size
        sort(words.begin(), words.end(), compare);
        
        // initially word chain size will be 1
        int len = 1; 
        for(auto word:words)           // irerate over the given words 
        {
            dp[word]=1;
            
            // check for the characters of current word
            for(int i=0; i<word.length(); i++) 
            {
                //removing ith alphabet from the string and check remaining string is available in the dp 
                string pred = word.substr(0,i) + word.substr(i+1); 
                
                // if it is available in dp then take that max len and go for next
                if(dp.find(pred) != dp.end()) 
                {
                    dp[word] = dp[pred]+1;                // updated
                    len = max(len, dp[word]);             // storing max one
                }
            }
        }
        return len;    
    }
};