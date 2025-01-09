//{ Driver Code Starts
// here

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &A, vector<int> &B,
                               vector<int> &C) {
    // Approach-1
    int i = 0, j = 0, k = 0;
    vector<int> result;

    while (i < A.size() && j < B.size() && k < C.size()) {
        // If all three are equal
        if (A[i] == B[j] && B[j] == C[k]) {
            // Check for duplicates in the result
            if (result.empty() || result.back() != A[i]) {
                result.push_back(A[i]);
            }
            i++;
            j++;
            k++;
        }
        // Move the smallest pointer forward
        else if (A[i] < B[j]) {
            i++;
        } else if (B[j] < C[k]) {
            j++;
        } else {
            k++;
        }
    }

    // If no common elements are found
    if (result.empty()) {
        result.push_back(-1);
    }

    return result;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr, crr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        string input3;
        getline(cin, input3);
        stringstream ss3(input3);
        int number3;
        while (ss3 >> number3) {
            crr.push_back(number3);
        }
        Solution ob;
        vector<int> res = ob.commonElements(arr, brr, crr);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl << "~\n";
    }
}
// } Driver Code Ends