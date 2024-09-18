//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Approach-1
        // int adjMatrix[V][V];
        // int m = edges.size();
        // for(auto it: edges){
        //     int first = it.first;
        //     int second = it.second;
        //     adjMatrix[first][second]=1;
        //     adjMatrix[second][first]=1;
        // }
        
        //Approach-2
        // vector<int> adjList[V];
        // for(auto it: edges){
        //     int u = it.first;
        //     int v = it.second;
        //     adjList[u].push_back(v);
        //     adjList[v].push_back(u);
        // }
        // return adjList;
        
        //Approach-3
        vector<vector<int>> adjList(V);
        for(auto it:edges){
            int u = it.first;
            int v = it.second;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return adjList;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>>edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i=0;i<V;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends