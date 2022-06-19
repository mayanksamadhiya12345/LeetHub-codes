class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        // first sort the given products string
        sort(products.begin(), products.end());
        
        // it will store the string and their corresponding occured strings
        unordered_map<string, vector<string>> mp;
        
        // iterate over the given products
        for (string &product : products) 
        {
            // it will the all substrings for current product[i]
            string sub = "";
            
            for (int i = 0; i < product.size(); i++) 
            {
                // each timer take the char of current product and push it to the sub vector
                // like : 'm'->'mo'->'mou'->'mous'->'mouse'
                sub.push_back(product[i]);
                
                // as given in the question for each typed word we need to give 3 suggestions not more than that
                // storing the current product for current stored word sub
                if (mp[sub].size() < 3) 
                    mp[sub].push_back(product);
            }
        }
        
        vector<vector<string>> ans;
        string subStr = "";
        for (int i = 0; i < searchWord.size(); i++) 
        {
            // it will add the curr char of search wors and according to that 
            // we will store the vector<string> in ans  from mp
            subStr += searchWord[i];
            ans.push_back(mp[subStr]);
        }
        return ans;
    }
};