//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    bool isValidSegment(const string& segment) {
    if (segment.empty() || segment.size() > 3) return false;
    if (segment[0] == '0' && segment.size() > 1) return false; // No leading zeros
    for (char c : segment) {
        if (!isdigit(c)) return false;
    }
    int num = stoi(segment);
    return num >= 0 && num <= 255;
}
  public:
    int isValid(string& s) {
    // code here
    stringstream ss(s);
    string segment;
    vector<string> segments;
    
    while (getline(ss, segment, '.')) {
        segments.push_back(segment);
    }
    
    if (segments.size() != 4) return false;
    
    for (const string& seg : segments) {
        if (!isValidSegment(seg)) return false;
    }
    
    return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends