//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfsSort(int node, vector<int> adj[], vector<int>& visited, stack<int>& st){
	    visited[node]=1;
	    for(auto it:adj[node]){
	        if(visited[it]==0){
	            dfsSort(it,adj,visited,st);
	        }
	    }
	    st.push(node);
	}
	void dfs(int node, vector<int> adj[], vector<int>& visited){
	    visited[node]=1;
	    for(auto it:adj[node]){
	        if(visited[it]==0){
	            dfs(it,adj,visited);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //Kosaraju's Algorithm
        vector<int> adjList[V];
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                adjList[i].push_back(it);  
            }
        }
        vector<int> revadj[V];
        int count=0;
        vector<int> visited(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfsSort(i,adjList,visited,st);
            }
        }
       fill(visited.begin(), visited.end(), 0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                revadj[it].push_back(i);
            }
        }
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(visited[node]==0){
                dfs(node,revadj,visited);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends