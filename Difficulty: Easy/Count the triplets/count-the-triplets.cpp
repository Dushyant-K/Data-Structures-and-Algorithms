//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
   int count = 0;

    // Sort the array
    sort(arr, arr+n);

    // Iterate over the array and fix one element
    for (int i = n - 1; i >= 2; i--) {
        int left = 0;
        int right = i - 1;

        // Use two pointers to find the other two elements
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == arr[i]) {
                count++;
                left++;
                right--;
            } else if (sum < arr[i]) {
                left++;
            } else {
                right--;
            }
        }
    }

    return count;
}
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends