class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        vector<string> a = {".-","-...","-.-.","-..",".","..-.","--.","....",
                  "..",".---","-.-",".-..","--","-.","---",".--.",
                  "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> s;
        
        for(auto it : words)
        {
            string tmp;
            for(auto i : it) tmp += a[i-'a'];
            s.insert(tmp);
        }
        
        return s.size();
    }
};