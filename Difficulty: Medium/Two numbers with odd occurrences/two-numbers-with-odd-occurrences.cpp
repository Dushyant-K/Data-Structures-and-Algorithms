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
        //Approach-1
        // map<long long int,int> mpp;
        // for(int i=0;i<N;i++){
        //     mpp[Arr[i]]++;
        // }
        // vector<long long int> ans;
        // for(auto it: mpp){
        //     if((it.second)%2==1)
        //     ans.push_back(it.first);
        // }
        // sort(ans.begin(),ans.end(),greater<int>());
        // return ans;
        
        //Approach-2
        
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