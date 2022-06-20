class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        // Declaring two sets for unique elemetnts
        // first set will contain all the unique words
        // set 2 will contain only those words who are going to be encoded
        
        set<string> s1(words.begin(),words.end());
        set<string> s2(words.begin(),words.end());
        
        // now iterate over the given words for cheking the endoing words
        for(auto word : words)
        {
            // now for each words we need to check all its suffixes
            // and if any suffix we found in our set2 them remove it
            // for time we have three suffix and suffix me has matched in our s2 so remove that
            
            // ime
            // me
            // e
            for(int j=1;j<word.size();j++)
            {
                s2.erase(word.substr(j));
            }
        }
        
        // now our set2 will contain only those words who are going to encoding
        // so just count the length for these words and add 1 each time for # also
        
        int cnt = 0;
        for(auto word : s2)
        {
            cnt += (word.size()+1);
        }
        return cnt;
    }
};