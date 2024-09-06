//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	bool isPrime(int n){
	    if(n==1 || n==0)return false;
	    int count=0;
	    for(int i=1;i<=sqrt(n);i++){
	        if(n%i==0)count++;
	        
	        if((n/i)!=i){
	           count++;
	        }
	    }
	    if(count==2)return true;
	    
	    return false;
	}
	vector<int>AllPrimeFactors(int N) {
	   // vector<int> ans;
	   // for(int i=1;i<=sqrt(N);i++){
	   //     if(N%i==0){
	   //         if(isPrime(i))ans.push_back(i);
	            
	   //         if((N/i)!=i){
	   //             if(isPrime(N/i))ans.push_back(N/i);
	   //         }
	   //     }
	   // }
	   // return ans;
	   
	   //Approach-2
	   vector<int> ans;
	   for(int i=2;i<=N;i++){
	       if(N%i==0){
	           ans.push_back(i);
	           while(N%i==0){
	               N = N/i;
	           }
	       }
	   }
	   return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends