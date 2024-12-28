//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    private:
    void removeMid(stack<int>& st, int count, int& mid){
        if(st.empty()){
            mid=(count)/2;
            return;
        }
        
        int element=st.top();
        
        st.pop();
        removeMid(st,count+1,mid);
        if(count!=mid)st.push(element);
        return;
    }
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // Approach-1(Recursion)
        if(s.empty())return;
        int mid=0;
        removeMid(s,0,mid);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        stack<int> s;
        int num;
        while (ss >> num) {
            s.push(num);
        }

        Solution ob;
        ob.deleteMid(s);
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends