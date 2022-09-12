class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        if(tokens.size()==0) return 0;            // if tokens array is empty then we can not achieve any score
        
        int score = 0;
        int i=0;
        int j=tokens.size()-1;
        sort(tokens.begin(),tokens.end());        // sort the tokens
        
        if(tokens[i]>power) return 0;             // if first value of array bigger than the power then also we can not achieve any score
        
        // untill we can not cross
        while(i<=j)
        {
            if(tokens[i]<=power)                   // if current token is lower value
            {
                power -= tokens[i++];              // decrease power by current token
                score++;                           // increase score by 1
            }
            
            else if(i==j && tokens[i]>power)     // if we left with last token then check we can execute it with current power or not, if not return break it
            {
                break;
            }
            
            else if(score>=1)                    // if we don't have curr token lower than power then go for score if it is bigger than 0 then take the max token into curr power for maximizing our last score
            {
                score--;                         // decrease score by 1
                power += tokens[j--];            // add up the max token from behind as array is sorted
            }
        }
        
        return score;
    }
};