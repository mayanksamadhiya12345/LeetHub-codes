class Solution {
public:    
    static bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] > b[1];   
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int k =boxTypes.size();
        int unit =0;
        for(int i =0 ; i<k ;i++){
            if(truckSize >= boxTypes[i][0]){
                truckSize -= boxTypes[i][0];
                unit += boxTypes[i][0]*boxTypes[i][1];
            }
            else{
                
                unit +=truckSize*boxTypes[i][1];
                break;
            }
        }
       return unit; 
    }
};