class Solution {
private:
    bool canMake ( int index , int bucketsize , vector<int> &matchsticks , vector<int> &bucket)
    {
        // base case 
        if ( index == matchsticks.size()) 
            return bucket[0]==bucket[1] and bucket[1]==bucket[2] and bucket[2]==bucket[3] ;
        
        
        // simple dfs backtrack 
        for ( int i = 0 ; i < 4 ; i ++ ){
            if ( bucket[i] + matchsticks.at(index) > bucketsize) continue ;  
            
            
            // concept of DP in optimization: if I have checked the same length before, 
            //why do I need to bother checking again?
            //Although we only have 4 sides in a square, we can still 
            //check if we have encountered the same length with the current match. 
          
            
            int j = i ;
            while ( --j >= 0) 
                if ( bucket[i] == bucket[j]) break;
            
            if ( j != -1 ) continue ;
            
            // noraml targetsum 
            bucket.at(i) += matchsticks.at(index);
            if ( canMake ( index + 1 , bucketsize , matchsticks , bucket )) return true;
            bucket.at(i) -= matchsticks.at(index);
        }
        
        return false;
    }
    
public:
    bool makesquare(vector<int>& matchsticks) 
    {
        // base case 
        int sum = 0 ;
        
        for ( int i : matchsticks) sum += i ;
        if ( sum == 0 or sum % 4 ) return false;
        
        // we know that the side of the square will be atleast the max element of the match array
        // sorting the array elements 
        sort( matchsticks.begin() , matchsticks.end() , greater<int>());
        
        // now i will make bucket of size sum / 4 
        // and try all possibility to form that sum
        vector<int> bucket(4, 0 );
        return canMake( 0 , sum / 4 , matchsticks , bucket);
    }
};