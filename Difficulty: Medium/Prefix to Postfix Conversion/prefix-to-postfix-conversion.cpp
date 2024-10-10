//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        //Approach-1
         stack<string> st;
        int i=pre_exp.length()-1;
        while(i>=0){
            if((pre_exp[i]>='A'&&pre_exp[i]<='Z')||(pre_exp[i]>='a'&&pre_exp[i]<='z')||(pre_exp[i]>='0'&&pre_exp[i]<='9')){
                st.push(string(1,pre_exp[i]));
            }
            else{
                string top1=st.top();
                st.pop();
                string top2=st.top();
                st.pop();
                string conv=top1+top2+pre_exp[i];
                st.push(conv);
            }
            i--;
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
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends