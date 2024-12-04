//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    void dfs(int src, vector<pair<int,int>> adj[], vector<int>& visited, stack<int>& st){
        visited[src]=1;
        for(auto it:adj[src]){
            if(visited[it.first]==0){
                dfs(it.first,adj,visited,st);
            }
        }
        st.push(src);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Approach-1(Topo sort along with relaxation of nodes)
        vector<pair<int,int>> adj[V];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        //Finding topo sort using dfs method
        vector<int> visited(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfs(i,adj,visited,st);
            }
        }
        
        ///Now we will start relaxing the nodes
        vector<int> dist(V,1e9);
        dist[0]=0;
        while(!st.empty()){
            if(st.top()==0)break;
            st.pop();
        }
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it:adj[node]){
                if(dist[node]+it.second<dist[it.first]){
                    dist[it.first]=dist[node]+it.second;
                }
            }
        }
        vector<int> ans(V);
        for(int i=0;i<V;i++){
            if(dist[i]==1e9){
                ans[i]=-1;
                continue;
            }
            ans[i]=dist[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends