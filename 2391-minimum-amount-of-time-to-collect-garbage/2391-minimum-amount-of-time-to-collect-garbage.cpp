class Solution {
public:
    int findTime(vector<string>& garbage, vector<int>& travel, char type, unordered_map<char, int> &mpp)
    {
        int minute = 0;
        
        //every house
        for(int i=0; i<garbage.size(); i++)
        {
            if(mpp[type]>0)
            {    
                //if that type of garbage remains to collect
                
                //garbage at a particular house
                for(int j=0; j<garbage[i].size(); j++)
                {
                    if(garbage[i][j]== type){
                        minute++;
                        mpp[type]--;
                    }
                }
                
                //add travelling cost if same type of garbage yet to collect
                if(mpp[type]>0)
                    minute += travel[i];
            }    
        }
        
        return minute;
    }
    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        //to track whether all the garbage collected of same type
        unordered_map<char, int> mpp;
        for(auto it: garbage)
        {
            for(auto jt: it)
                mpp[jt]++;
        }
        
        vector<char> type = {'P', 'G', 'M'};    //paper, glass, metal
        int minutes = 0;
        for(int i=0; i<type.size(); i++)
        {
            minutes += findTime(garbage, travel, type[i], mpp);
        }
        
        return minutes;
    }
};