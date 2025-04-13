//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
    private:
    string reverseStr(string str){
        int i = 0, j = str.length() - 1;
        while (i < j) {
            swap(str[i], str[j]);
            i++;
            j--;
        }
        return str;
    }
  public:
    string decToBinary(int n) {
        //Approach-1
        if (n == 0) return "0";
        
        string binary = "";
        while (n > 0) {
            binary += (n % 2 == 0 ? '0' : '1');
            n /= 2;
        }

        return reverseStr(binary);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.decToBinary(n) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends