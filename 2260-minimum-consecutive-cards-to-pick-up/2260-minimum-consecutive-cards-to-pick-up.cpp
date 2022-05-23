class Solution {
public:
    int minimumCardPickup(vector<int>& cards) 
    {
        // created a visited vector that will store the visited values
        vector<int> visited(1e6+1, -1);
        
        // it will store the minimum  consecutive cards
        int mn = INT_MAX;
        
        // iterate over the cards
        for(int i=0; i<cards.size(); i++)
        {
            // if current value is already visited it means there is second occurance of same value
            // and it may be our answer so we will check for minimum and store the size of consecutive value
            if(visited[cards[i]] != -1)
            {   
                mn  = min(mn, i- visited[cards[i]]+1);                     // (i=right_pointer - visited[cards[i]]=left_pointer) +2 because (0 base indexing)
            }
           
            // mark the current value as visited instead of -1
            visited[cards[i]] = i;
        }
        
        // if mn value is still max then there is no consecutive value so return -1 else return mn value that we founded
        return mn==INT_MAX ? -1 : mn;
    }
};