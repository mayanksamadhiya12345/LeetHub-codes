class Solution {
public:
    bool isoneB(int val){
        int res = val & 128;
        
        if(res != 128)
            return true;
        return false;
    }
    
    
    bool istwoB(int val){
        int res = val & 192;
        if(res == 192 && val < 224)
            return true;
        
        return false;
    }
    
    bool isthreeB(int val){
        int res = val & 224;
        
        if(res == 224 && val < 240)
            return true;
        
        return false;
    }
    
    bool isfourB(int val){
        int res = val & 240;
        
        if(res == 240 && val < 248)
            return true;
        return false;
    }
    
    int findByte(int val){
        if(isoneB(val))
            return 1;
        if(istwoB(val))
            return 2;
        if(isthreeB(val))
            return 3;
        if(isfourB(val))
            return 4;
        return -1;   
    }
    
    bool tensig(int val)
    {
        int res = val & 128;
        if(res == 128 && val < 192)
            return true;
        return false;
    }
    
    bool validUtf8(vector<int>& data) 
    {
        int n = data.size();
        
        
        for(int i=0; i<n; i++){
            int b = findByte(data[i]); // Finding whether the number is 1/2/3/4 byte
            
            if(b == -1) // If it is not in 1 to 4 bytes
                return false;
            
            int j;  // Checking whether b-1 bytes are having 10 as significant bits
            for(j=i+1; j<n && j<i+b; j++){
                if(tensig(data[j]))
                    continue;
                return false;
            }
            
            if(j != i+b)    // If we failed to check some bytes of b-1 bytes
                return false;
            
            i = j-1; // Going for next sequence
        }
        
        return true;
    }
};