//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isParenthesisBalanced(string& s) {
    std::stack<char> stack;
    std::unordered_map<char, char> brackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char ch : s) {
        // If it's an opening bracket, push it onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        // If it's a closing bracket, check for a matching opening bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            // If stack is empty or the top of the stack doesn't match, it's unbalanced
            if (stack.empty() || stack.top() != brackets[ch]) {
                return false;
            }
            stack.pop(); // Pop the matching opening bracket
        }
    }

    // If stack is empty, all brackets matched; otherwise, they didn't
    return stack.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isParenthesisBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends