class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        if(tokens.size()==0) return 0;
        
        int score = 0;
        int i=0;
        int j=tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        
        if(tokens[i]>power) return 0;
        
        while(i<=j)
        {
            if(tokens[i]<=power)
            {
                power -= tokens[i];
                score++;
                i++;
            }
            
            else if(i==j && tokens[i]>power)
            {
                break;
            }
            
            else if(score>=1)
            {
                score--;
                power += tokens[j];
                j--;
            }
        }
        
        return score;
    }
};