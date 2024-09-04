//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		     int n = v.size();
    // Sorting the array
    std::sort(v.begin(), v.end());

    // Calculating the median
    if (n % 2 == 0) {
        // If size is even, median is the average of the two middle elements
        return (v[n / 2 - 1] + v[n / 2]) / 2;
    } else {
        // If size is odd, median is the middle element
        return v[n / 2];
    }
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends