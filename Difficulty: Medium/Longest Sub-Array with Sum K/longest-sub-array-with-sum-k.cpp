//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Approach-1
        map<int,int> mpp;
        int maxLength=0;
        // mpp[0]=-1;
        int prefixSum=0;
        for(int i=0;i<N;i++){
            prefixSum+=A[i];
            if(prefixSum==K){
                maxLength = i+1;
            }
            int rem = prefixSum-K;
            if(mpp.find(rem)!=mpp.end()){
                maxLength = max(maxLength,i-mpp[rem]);
            }
            if(mpp.find(prefixSum)==mpp.end())mpp[prefixSum]=i;//Ed
        }
        return maxLength;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends