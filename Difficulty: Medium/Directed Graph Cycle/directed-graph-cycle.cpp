//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool detectCycle(int start, vector<int> adj[], vector<int>& visited, vector<int>& pathVisited){
        visited[start]=1;
        pathVisited[start]=1;
        for(auto it:adj[start]){
            if(visited[it]==0){
                if(detectCycle(it,adj,visited,pathVisited))return true;
            }
            else{
                if(pathVisited[it]==1)return true;
            }
        }
        pathVisited[start]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // Approach-1
        // vector<int> visited(V,0);
        // vector<int> pathVisited(V,0);
        // for(int i=0;i<V;i++){
        //     if(!visited[i]){
        //         if(detectCycle(i,adj,visited,pathVisited))return true;
        //     }
        // }
        
        // return false;
        
        //Approach-2(Using BFS-Kahn's Algorithm)
       vector<int> indegree(V,0);
	   queue<int> q;
	   for(int i=0;i<V;i++){
	       for(auto it:adj[i]){
	           indegree[it]++;
	       }
	   }
	   for(int i=0;i<V;i++){
	       if(indegree[i]==0){
	           q.push(i);
	       }
	   }
	   vector<int> topo;
	   while(!q.empty()){
	       int node = q.front();
	       topo.push_back(node);
	       q.pop();
	       for(auto it:adj[node]){
	           indegree[it]--;
	           if(indegree[it]==0)q.push(it);
	       }
	   }
	   return (topo.size()==V)?false:true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends