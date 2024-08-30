//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr + n);
    sort(dep, dep + n);

    int platforms_needed = 1; // Initial platform needed
    int result = 1; // To store the final result

    int i = 1, j = 0; // i points to the next arriving train, j points to the next departing train

    // Process all events in sorted order
    while (i < n && j < n) {
        // If next train arrives before the current train departs
        if (arr[i] <= dep[j]) {
            platforms_needed++; // One more platform is needed
            i++;
        } 
        // If the train departs before the next train arrives
        else {
            platforms_needed--; // One platform is freed
            j++;
        }

        // Update the result if needed
        result = max(result, platforms_needed);
    }

    return result;
}

};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends