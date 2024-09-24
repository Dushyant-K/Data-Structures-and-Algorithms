//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer=1;
    void dfs(int node, int parent, vector<int> adj[], vector<int>& visited, vector<int>& tin
    , vector<int>& low,vector<int>& mark){
        visited[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        int count=0;
        for(auto it:adj[node]){
            if(it==parent)continue;
            if(visited[it]==0){
                dfs(it,node,adj,visited,tin,low,mark);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node]&&parent!=-1){
                    mark[node]=1;
                }
                 count++;
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
        if(count>1&&parent==-1)mark[node]=1;
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Approach-1(Dfs Algorihtm)
        vector<int> visited(V,0);
        vector<int> tin(V,0);
        vector<int> low(V,0);
        vector<int> mark(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfs(i,-1,adj,visited,tin,low,mark);
            }
        }
        vector<int> ans;
        for(int i=0;i<mark.size();i++){
            if(mark[i]==1)ans.push_back(i);
        }
        if(ans.size()==0)return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends