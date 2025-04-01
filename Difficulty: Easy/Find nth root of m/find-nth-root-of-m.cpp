//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
	public:
	int func(long long mid, int n, int m){
	    long long ans=1;
	    for(int i=1;i<=n;i++){
	        ans = ans*mid;
	        if(ans>m)return 2;
	    }
	    if(ans==m) return 1;
	    return 0;
	}
	int nthRoot(int n, int m)
	{
	    int low=1;
	    int high=m;
	    while(low<=high){
	        long long mid = (low+high)/2;
	        long long val=func(mid,n,m);
	        if(val==1){
	            return mid;
	        }
	        else if(val==0){
	            low=mid+1;
	        }
	        else{
	            high=mid-1;
	        }
	    }
	    return -1;
	}  
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends