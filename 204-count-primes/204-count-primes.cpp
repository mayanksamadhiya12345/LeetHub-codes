class Solution {
public:
    int countPrimes(int n) {
        
        // initially assume that all the numbers till n numbers are prime, hence all will are true
        vector<bool> arePrimes(n, true);
        
        // initialize answer count with 0
        int answer=0;
        
        // now we'll scan the numbers starting from 2 to n
        for(int number=2; number<n; number++)
        {      
            // if the number is already a prime number, continue without doing anyhing in the loop 
            if(arePrimes[number] != true) continue;
            
            // we'll reach here if and only if the number is not prime
            // so for current prime value , first increase the count of answer
            answer++;
            
            // mark all multiples of number as not prime (till n)
            // starting from arePrimes[2 * 2] = not prime
            // gong like are primes[4 + 2] = not prime
            // .......are primes[6 + 2] = not prime
            for(long multiple=(long)number * number; multiple<n; multiple+=number)
            { 
                // mark the multiple of number as not prime
                arePrimes[multiple] = false;              
            }          
        }
          
        //return the count
        return answer;    
    }
};