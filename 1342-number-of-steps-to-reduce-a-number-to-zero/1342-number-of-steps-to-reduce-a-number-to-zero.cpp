class Solution {
public:
    int numberOfSteps(int num) 
    {
        int ans = 0;
        
        while(num)
        {  
            // if this loop will run it means we have a number so just increase our numbner by one
            ans++;
            
            // if value is even then just update by it half
            if(num%2 == 0)
            { 
                num = num/2;
            }
            
            // if value is odd then subtract 1 from it
            else
            {
                num--;
            }   
        }
        return ans;
    }
};