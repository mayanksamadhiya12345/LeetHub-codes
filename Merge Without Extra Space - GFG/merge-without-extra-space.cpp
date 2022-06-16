// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
public:
    //Function to merge the arrays.
    void swap(long long* a, long long* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void merge(long long arr1[], long long arr2[], int n1, int n2)
    {
        int gap = n1+n2;
        gap = gap/2 + gap%2;
        
        int i = 0;
        int j = gap;
        
        while(gap >= 1)
        {
            if(j<n1+n2)
            {
                if(i<n1 && j<n1)
                {
                    if(arr1[i] > arr1[j])
                        swap(&arr1[i],&arr1[j]);
                    i++;
                    j++;
                }
                
                if(i>=n1 && j>=n1)
                {
                    if(arr2[i-n1] > arr2[j-n1])
                        swap(&arr2[i-n1],&arr2[j-n1]);
                    i++;
                    j++;
                }
                
                if(i<n1 && j>=n1)
                {
                    if(arr1[i] > arr2[j-n1])
                        swap(&arr1[i],&arr2[j-n1]);
                    i++;
                    j++;
                }
            }
            else
            {
                if(gap > 1)
                {
                    gap = (gap/2) + (gap%2);
                    i = 0;
                    j = gap;
                }
                else
                {
                    gap = 0;
                }
            }
        }
    }
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends