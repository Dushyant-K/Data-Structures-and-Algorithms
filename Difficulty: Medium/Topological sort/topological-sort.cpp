//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int start,vector<int> adj[], vector<int>& visited, stack<int>& st){
	    visited[start]=1;
	    for(auto it: adj[start]){
	        if(visited[it]==0){
	            dfs(it,adj,visited,st);
	        }
	    }
	    st.push(start);
	    return;
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // Approach-1(Base Method is to find with DFS)
	   // vector<int> visited(V,0);
	   // vector<int> ans;
	   // stack<int> st;
	   // for(int i=0;i<V;i++){
	   //     if(visited[i]==0){
	   //         dfs(i,adj,visited,st);
	   //     }
	   // }
	   // while(!st.empty()){
	   //     int temp = st.top();
	   //     ans.push_back(temp);
	   //     st.pop();
	   // }
	   // return ans;
	   
	   //Approach-2(Kahn's Algorithm)
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
	   return topo;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends