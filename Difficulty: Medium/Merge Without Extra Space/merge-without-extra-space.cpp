//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // Approach-1
        int n=a.size();
        int m=b.size();
        
        int gap = (n + m + 1) / 2; // Initial gap
    while (gap > 0) {
        int i, j;

        // Comparing elements in the first array
        for (i = 0; i + gap < n; i++) {
            if (a[i] > a[i + gap]) {
                swap(a[i], a[i + gap]);
            }
        }

        // Comparing elements between both arrays
        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++) {
            if (a[i] > b[j]) {
                swap(a[i], b[j]);
            }
        }

        // Comparing elements in the second array
        for (j = 0; j + gap < m; j++) {
            if (b[j] > b[j + gap]) {
                swap(b[j], b[j + gap]);
            }
        }

        // Reduce the gap using the ceil function
        gap = (gap == 1) ? 0 : (gap + 1) / 2;
    }
    }
};

//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends