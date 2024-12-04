//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // Approach-1(BFS Algorithim)
        vector<int> adj[N];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(N,1e9);
        queue<pair<int,int>> q;
        q.push({src,0});
        dist[src]=0;
        
        //Now the containers are ready
        while(!q.empty()){
            int node=q.front().first;
            int distance=q.front().second;
            q.pop();
            //Now start relaxing nodes
            for(auto it:adj[node]){
                if(distance+1<dist[it]){
                    dist[it]=distance+1;
                    q.push({it,dist[it]});
                }
            }
        }
        vector<int> ans(N);
        for(int i=0;i<N;i++){
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends