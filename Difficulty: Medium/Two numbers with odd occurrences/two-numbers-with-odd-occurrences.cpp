//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // Approach-1
        int xor1=0;
        for(int i=0;i<N;i++){
            xor1=xor1^Arr[i];
        }
        int rightmost=0;
        rightmost = xor1 & ~(xor1 - 1);
        int xorZero=0;
        int xorOne=0;
        for(int i=0;i<N;i++){
            if(Arr[i]&(rightmost))xorOne=xorOne^Arr[i];
            else xorZero=xorZero^Arr[i];
        }
        if(xorOne>xorZero)return {xorOne,xorZero};
        return {xorZero,xorOne};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends