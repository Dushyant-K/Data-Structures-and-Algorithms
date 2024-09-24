//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool dfs(int node, int parent, vector<int>& visited, vector<int> adj[]){
      visited[node]=1;
      for(auto it:adj[node]){
          if(visited[it]==0){
              if(dfs(it,node,visited,adj))return true;
          }
          else{
              if(parent!=it)return true;
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Approach-1
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(dfs(i,-1,visited,adj))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends