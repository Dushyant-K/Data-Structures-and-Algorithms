//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    bool isPossible(int color, int idx, vector<vector<int>> adjList, vector<int> colors){
        for(auto it:adjList[idx]){
            if(colors[it]==color)return false;
        }
        return true;
    }
    bool color(int idx, int v, vector<vector<int>> adjList, int m, vector<int>& colors){
        if(idx==v)return true;
        
        for(int i=1;i<=m;i++){
            if(isPossible(i,idx,adjList,colors)){
                colors[idx]=i;
                if(color(idx+1,v,adjList,m,colors))return true;
                colors[idx]=0;
            }
        }
        return false;
    }
  public:
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // Approach-1
        vector<vector<int>> adjList(v);
        for(auto it:edges){
            int u = it.first;
            int v = it.second;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> colors(v,0);
        return color(0,v,adjList,m,colors);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends