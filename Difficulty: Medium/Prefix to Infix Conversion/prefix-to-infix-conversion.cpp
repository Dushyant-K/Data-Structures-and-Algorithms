//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        int i = pre_exp.length() - 1;
        stack<string> st;

        while (i >= 0) {
            // If the character is an operand, push it to the stack.
            if ((pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') || (pre_exp[i] >= 'a' && pre_exp[i] <= 'z') || (pre_exp[i] >= '0' && pre_exp[i] <= '9')) {
                string s(1, pre_exp[i]); // Convert char to string.
                st.push(s);
            }
            // If the character is an operator.
            else {
                // Pop two operands from the stack.
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                // Create a new string with the operator between the operands.
                string temp = '(' + t1 + pre_exp[i] + t2 + ')';
                st.push(temp);
            }
            i--; // Move to the previous character.
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends