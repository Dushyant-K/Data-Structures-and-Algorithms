//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool detectCycleDFS(int src, int parent, vector<int> adj[], int visited[]){
        visited[src] = 1;
       for(auto it: adj[src]){
           if(visited[it]==0){
               if(detectCycleDFS(it,src,adj,visited))return true;
           }
           else{
               if(it!=parent)return true;
           }
       }
       return false;
    }
    // Function to detect cycle in an undirected graph.
    // bool detectCycleBFS(int src, vector<int> adj[], int visited[]){
    //     visited[src]=1;
    //     queue<pair<int,int>> q;
    //     q.push({src,-1});
    //     while(!q.empty()){
    //         int node = q.front().first;
    //         int parent = q.front().second;
    //         for(auto it: adj[node]){
    //             if(visited[it]==0){
    //                 visited[it]=1;
    //                 q.push({it,node});
    //             }
    //             else{
    //                 if(parent!=it){
    //                     return true;
    //                 }
    //             }
    //         }
    //     }
    //     return false;
    // }
    bool isCycle(int V, vector<int> adj[]) {
    //     // Approach-1
    //     int visited[V]={0};
    //     for(int i=0;i<V;i++){
    //         if(visited[i]==0){
    //             if(detectCycleBFS(i,adj,visited))return true;
    //         }
    //     }
    //     return false;
    
    //Approach-2
    int visited[V]={0};
    for(int i=0;i<V;i++){
        if(visited[i]==0){
            if(detectCycleDFS(i,-1,adj,visited))return true;
        }
    }
    return false;;
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