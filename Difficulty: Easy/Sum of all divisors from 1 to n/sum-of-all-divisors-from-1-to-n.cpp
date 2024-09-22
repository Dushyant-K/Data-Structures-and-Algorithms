//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumofDivisor(int n){
        //Approach-1
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(n%i==0)sum+=i;
        }
        return sum;
    }
    long long sumOfDivisors(int N)
    {
        //Approach-1
        // long long sum;
        // for(int i=1;i<=N;i++){
        //     sum+=sumofDivisor(i);
        // }
        // return sum;
        
        //Approach-2
         long long sum = 0;
        // Loop through each number as a potential divisor
        for(int i = 1; i <= N; i++){
            // Add i to the sum for every multiple of i
            sum += (N / i) * i;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends