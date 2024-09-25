//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    bool ls(int arr[], int N, int n){
        for(int i=0;i<N;i++){
            if(arr[i]==n)return true;
        }
        return false;
    }
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Approach-1
    //   int maxCount=0;
    //   for(int i=0;i<N;i++){
    //       int count=1;
    //       while(ls(arr,N,arr[i]+count)==true){
    //           count++;
    //           maxCount = max(maxCount,count);
    //       }
    //   }
    //   return maxCount;
    
    //Approach-2
    // sort(arr,arr+N);
    // int lastSmaller =INT_MIN;
    // int longest=1;
    // int count=0;
    // for(int i=0;i<N;i++){
    //     if(arr[i]-1==lastSmaller){
    //         count++;
    //         lastSmaller = arr[i];
    //       }
    //       else{
    //             lastSmaller = arr[i];
    //           count=1;
    //       }
    //       longest = max(longest,count);
    //      }
    //      return longest;
    
    //Approach-3
    if(N==0)return 0;
    set<int> st;
    int longest=1;
    for(int i=0;i<N;i++){
        st.insert(arr[i]);
    }
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int count=1;
            while(st.find(it+1)!=st.end()){
                it++;
                count++;
            }
            longest = max(longest,count);
        }
    }
    return longest;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends